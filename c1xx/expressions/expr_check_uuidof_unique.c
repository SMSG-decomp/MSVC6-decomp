c1_guid * __cdecl expr_check_uuidof_unique(c1_symbol *cls,c1_u8 *reported)

{
  int *piVar1;
  c1_symbol *cls_00;
  c1_guid *pcVar2;
  int iVar3;
  c1_guid *pcVar4;
  c1_guid *pcVar5;
  
  piVar1 = symtab_15f4_lookup(cls);
  iVar3 = *piVar1;
  pcVar4 = (c1_guid *)0x0;
  do {
    pcVar5 = pcVar4;
    if ((*(byte *)(iVar3 + 0xc) & 3) == 0) {
      cls_00 = type_class_symbol(*(c1_type **)(iVar3 + 0x10));
      if (cls_00 == (c1_symbol *)0x0) {
        return (c1_guid *)0x0;
      }
      if ((cls_00->flags21 & 0x40) == 0) {
        if ((((cls_00->detail).cls)->flags3e & 1) == 0) goto LAB_10499875;
        pcVar2 = expr_check_uuidof_unique(cls_00,reported);
      }
      else {
        pcVar2 = sym_extra_record(cls_00);
      }
      if (((pcVar2 != (c1_guid *)0x0) && (pcVar5 = pcVar2, pcVar4 != (c1_guid *)0x0)) &&
         (pcVar5 = pcVar4, pcVar2 != pcVar4)) {
        diag_error(0x314,cls);
        *reported = '\x01';
        return (c1_guid *)0x0;
      }
    }
LAB_10499875:
    iVar3 = *(int *)(iVar3 + 4);
    pcVar4 = pcVar5;
    if (iVar3 == 0) {
      return pcVar5;
    }
  } while( true );
}

