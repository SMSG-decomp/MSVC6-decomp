c2_tuple * lower_int64_tuple_case_16a(c2_tuple *t,c2_tuple *result)

{
  c2_symbol *pcVar1;
  c2_tuple *pcVar2;
  
  pcVar2 = lower_small_block_copy_as_scalar(t);
  if ((((pcVar2 != (c2_tuple *)0x0) && (pcVar2->dst->kind == '\x01')) &&
      (pcVar1 = pcVar2->dst->sym, pcVar1->cls == '\x03')) && (pcVar1->def != (c2_tuple *)0x0)) {
    pcVar1->def = pcVar2;
  }
  return result;
}

