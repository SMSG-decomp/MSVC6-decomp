void __fastcall retype_symbol_chain_to_local(c2_symbol *s)

{
  int a;
  c2_symbol *pcVar1;
  c2_bitset *bs;
  uint32_t uVar2;
  c2_fe_symbol *pcVar3;
  int16_t kind;
  int arena;
  uint8_t f;
  uint32_t attrs;
  
  attrs = 0;
  f = '\x04';
  arena = 1;
  a = s->size;
  kind = 1;
  uVar2 = type_class_to_symbol_class(s->type);
  pcVar3 = fe_symbol_new_local_cur((uint16_t)uVar2,a,kind,arena,f,attrs);
  bs = g_local_symbol_ids;
  for (pcVar1 = s->storage; pcVar1 != (c2_symbol *)0x0; pcVar1 = pcVar1->part_next) {
    g_local_symbol_ids = bs;
    pcVar1->cls = '\x04';
    pcVar1->fe = pcVar3;
    bitset_set(bs,pcVar1->id);
    bs = g_local_symbol_ids;
  }
  g_local_symbol_ids = bs;
  return;
}

