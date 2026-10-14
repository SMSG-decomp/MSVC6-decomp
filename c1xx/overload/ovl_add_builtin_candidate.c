void __thiscall
ovl_add_builtin_candidate
          (c1_ovl_resolution *res,c1_builtin_operator_row *row,c1_type *type,c1_type *type2,
          int *count)

{
  int iVar1;
  byte bVar2;
  char cVar3;
  c1_ovl_candidate *pcVar4;
  
  if (row != (c1_builtin_operator_row *)0x0) {
    bVar2 = (byte)type->code;
    if ((((char)bVar2 < '\0') && ((bVar2 & 0x8f) == 0x80)) && ((char)row->need_lvalue == '\0')) {
      type = type_base(type);
    }
    if (((type2 != (c1_type *)0x0) && (bVar2 = (byte)type2->code, (char)bVar2 < '\0')) &&
       ((bVar2 & 0x8f) == 0x80)) {
      type2 = type_base(type2);
    }
    for (pcVar4 = res->candidates; pcVar4 != (c1_ovl_candidate *)0x0; pcVar4 = pcVar4->next) {
      if ((((pcVar4->flags & 4) != 0) &&
          (cVar3 = ovl_builtin_types_equal(pcVar4->builtin_left,type), cVar3 != '\0')) &&
         (cVar3 = ovl_builtin_types_equal(pcVar4->builtin_right,type2), cVar3 != '\0')) {
        return;
      }
    }
    *count = *count + 1;
    iVar1 = res->ncandidates;
    res->ncandidates = iVar1 + 1;
    if (res->candidates + iVar1 == (c1_ovl_candidate *)0x0) {
      pcVar4 = (c1_ovl_candidate *)0x0;
    }
    else {
      pcVar4 = ovl_builtin_candidate_init
                         (res->candidates + iVar1,row,type,type2,
                          res->conversions + res->nconversions,res->tail);
    }
    res->tail = pcVar4;
    res->nconversions = res->nconversions + res->nargs;
  }
  return;
}

