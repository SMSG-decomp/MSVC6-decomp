char __fastcall type_has_linkage_for_template(c1_type *type)

{
  c1_u16 cVar1;
  c1_type_list *pcVar2;
  c1_symbol *pcVar3;
  byte bVar4;
  char cVar5;
  c1_type *pcVar6;
  ushort uVar7;
  c1_type **ppcVar8;
  int iVar9;
  c1_symbol *pcVar10;
  
  cVar5 = (char)type->code;
  do {
    if (-1 < cVar5) {
      if ((type->code & 0x300) != 0) {
        pcVar10 = (type->extra).cls;
        if ((pcVar10->kind & 0x1f) == 4) {
          cVar1 = pcVar10->scope_index;
          while ((cVar1 != 0 &&
                 (pcVar3 = g_scope_vector->entries[(short)cVar1], (pcVar3->kind & 0x1f) == 4))) {
            cVar1 = pcVar3->scope_index;
            pcVar10 = pcVar3;
          }
        }
        if (((pcVar10->flags3 & 8) != 0) || (pcVar10->name == g_name_unnamed)) {
          return '\0';
        }
      }
      return '\x01';
    }
    pcVar10 = (c1_symbol *)0x0;
    bVar4 = (byte)type->code;
    if ((((char)bVar4 < '\0') && ((bVar4 & 0x8f) == 0x82)) && ((type->flags & 0x18) == 0x18)) {
LAB_10482e77:
      pcVar10 = (type->extra).cls;
LAB_10482e7a:
      if (pcVar10 != (c1_symbol *)0x0) {
        if ((pcVar10->kind & 0x1f) == 4) {
          cVar1 = pcVar10->scope_index;
          while ((cVar1 != 0 &&
                 (pcVar3 = g_scope_vector->entries[(short)cVar1], (pcVar3->kind & 0x1f) == 4))) {
            cVar1 = pcVar3->scope_index;
            pcVar10 = pcVar3;
          }
        }
        if ((pcVar10->flags3 & 8) != 0) {
          return '\0';
        }
        if (pcVar10->name == g_name_unnamed) {
          return '\0';
        }
      }
    }
    else {
      uVar7 = type->code & 0x8f;
      if ((uVar7 == 0x8a) || (uVar7 == 0x8e)) {
        if (uVar7 == 0x85) {
          pcVar6 = type_base(((type->extra).params)->this_type);
          pcVar10 = (pcVar6->extra).cls;
        }
        else {
          if ((uVar7 == 0x8a) || (uVar7 == 0x8e)) goto LAB_10482e77;
          pcVar10 = (c1_symbol *)0x0;
        }
        goto LAB_10482e7a;
      }
      if ((bVar4 & 0x83) == 0x81) {
        if (uVar7 == 0x85) {
          pcVar6 = type_base(((type->extra).params)->this_type);
          pcVar10 = (pcVar6->extra).cls;
        }
        pcVar2 = ((type->extra).params)->list;
        ppcVar8 = pcVar2->types;
        for (iVar9 = pcVar2->count; 0 < iVar9; iVar9 = iVar9 + -1) {
          cVar5 = type_has_linkage_for_template(*ppcVar8);
          if (cVar5 == '\0') {
            return '\0';
          }
          ppcVar8 = ppcVar8 + 1;
        }
        goto LAB_10482e7a;
      }
    }
    type = type_base(type);
    cVar5 = (char)type->code;
  } while( true );
}

