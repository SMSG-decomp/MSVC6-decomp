int __fastcall iterator_begin_from_record(c1_decl_spec_scan *state)

{
  c1_u8 *pcVar1;
  int iVar2;
  c1_u32 *pcVar3;
  c1_u32 *spec_dst;
  
  if (state->ntokens == 0) {
    pcVar1 = state->token;
    state->from_token = '\x01';
    state->named_type = *(c1_type **)(pcVar1 + 0x20);
    state->type_sym = *(c1_symbol **)(pcVar1 + 0x24);
    state->insert_fn = (void *)0x0;
    state->cv = state->named_type->flags;
    pcVar3 = (c1_u32 *)(pcVar1 + 8);
    spec_dst = (c1_u32 *)state->spec;
    for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
      *spec_dst = *pcVar3;
      pcVar3 = pcVar3 + 1;
      spec_dst = spec_dst + 1;
    }
    return 0;
  }
  return 1;
}

