void __thiscall decl_append_derived_check(c1_decl_record *rec,c1_type *layer)

{
  c1_u16 *pcVar1;
  c1_type *pcVar2;
  ushort auStack_10 [2];
  uint extra_word1;
  ushort auStack_8 [2];
  uint mods_position;
  
  rec->layer_flags = rec->layer_flags | 1;
  if (rec->chain_head != (c1_type *)0x0) {
    pcVar2 = rec->chain_tail;
    switch((byte)pcVar2->code & 0x8f) {
    case 0x80:
      pcVar2->code = (c1_u16)CONCAT31((byte)(layer->code >> 8) & 0xe0,0x84);
      break;
    case 0x81:
    case 0x85:
      diag_error(0x5b);
      auStack_10[0] = 0;
      extra_word1 = 0;
      auStack_8[0] = 0;
      mods_position = 0;
      decl_add_pointer_modifier(rec,auStack_8,auStack_10);
      rec->chain_tail->code = 0x86;
      break;
    case 0x82:
      pcVar2->code = (c1_u16)CONCAT31((byte)(layer->code >> 8) & 0xe0,0x86);
      break;
    case 0x83:
      diag_error(0x5c);
      (rec->chain_tail->extra).cls = (c1_symbol *)0x0;
      rec->chain_tail->code = 0x82;
      break;
    case 0x8a:
      pcVar2->code = (c1_u16)CONCAT31((byte)(layer->code >> 8) & 0xe0,0x8e);
      if ((layer->code & 0x8f) != 0x85) {
        decl_apply_declspec_based_fragment(layer,(int *)rec,0);
        return;
      }
    }
    pcVar2 = rec->chain_tail;
    if ((pcVar2->code & 0x8f) == 0x83) {
      pcVar2 = type_skip_arrays(pcVar2->base);
    }
    if ((pcVar2->flags & 8) != 0) {
      diag_error(0xd4,rec->sym);
      rec->flags = rec->flags | 1;
      pcVar1 = &rec->chain_tail->flags;
      *pcVar1 = *pcVar1 & 0xffe7;
    }
  }
  return;
}

