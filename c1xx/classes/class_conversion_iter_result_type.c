c1_type * __fastcall class_conversion_iter_result_type(c1_member_iter *iter)

{
  uint uVar1;
  c1_symbol *sym;
  c1_type *pcVar2;
  c1_type local_10;
  
  sym = (c1_symbol *)((int)iter->current + -8);
  if ((*(byte *)((int)iter->current + -8) & 0x1f) != 8) {
    sym = (c1_symbol *)ovl_first_function_of_set(sym);
  }
  pcVar2 = sym->type->base;
  if ((pcVar2->flags & 0x1f) != 0) {
    uVar1._0_2_ = pcVar2->code;
    uVar1._2_2_ = pcVar2->flags;
    local_10.base = pcVar2->base;
    local_10.extra = pcVar2->extra;
    local_10._0_4_ = uVar1 & 0x1fffff;
    local_10.debug_index = pcVar2->debug_index;
    pcVar2 = type_intern(&local_10);
  }
  return pcVar2;
}

