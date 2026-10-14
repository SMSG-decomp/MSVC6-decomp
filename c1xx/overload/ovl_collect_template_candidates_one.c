void __thiscall ovl_collect_template_candidates_one(void *result,c1_symbol *sym)

{
  byte bVar1;
  c1_tmpl_deduction *value;
  c1_symbol_vector *pcVar2;
  short *psVar3;
  
  if ((sym->kind & 0x1f) == 0x1a) {
    bVar1 = *(byte *)(*(int *)sym->type + 0x35);
  }
  else {
    bVar1 = *(byte *)((int)&sym->tail + 9);
  }
  if ((bVar1 >> 5 & 1) != 0) {
    value = tmpl_deduce_from_call(result,sym);
    if (value != (c1_tmpl_deduction *)0x0) {
      if (*(int *)((int)result + 4) == 0) {
        pcVar2 = symtab_record_new(1);
        *(c1_symbol_vector **)((int)result + 4) = pcVar2;
      }
      psVar3 = vector_find_or_add(*(short **)((int)result + 4),(int)value);
      *(short **)((int)result + 4) = psVar3;
    }
  }
  return;
}

