void __fastcall type_check_based_allocation(c1_declaration *decl)

{
  uint uVar1;
  c1_type *pcVar2;
  int iVar3;
  c1_symbol *tag_2;
  c1_symbol *pcVar4;
  c1_symbol *tag;
  c1_symbol *tag_3;
  
  tag_2 = decl->sym;
  uVar1._0_1_ = tag_2->storage;
  uVar1._1_1_ = tag_2->flags21;
  uVar1._2_1_ = tag_2->flags22;
  uVar1._3_1_ = tag_2->flags23;
  switch(uVar1 & 7) {
  case 1:
    if ((decl->flags2c & 4) == 0) {
      return;
    }
  case 2:
  case 3:
    pcVar2 = type_skip_arrays(tag_2->type);
    if (((byte)pcVar2->flags >> 5 & 1) == 0) {
      if ((tag_2->flags3 & 4) == 0) {
        sym_set_segment_from(tag_2,(int)g_bss_seg_name);
      }
      else {
        sym_set_segment_from(tag_2,(int)g_data_seg_name);
      }
    }
    else {
      sym_set_segment_from(tag_2,(int)g_const_seg_name);
    }
    break;
  case 4:
  case 5:
  case 6:
    if ((tag_2->flags23 & 1) != 0) {
      if (tag_2 == (c1_symbol *)0x0) {
        tag_2 = sym_new_from_declarator(decl,3);
      }
      diag_error(0xb9,tag_2);
    }
    break;
  case 7:
    goto code_r0x10607ba6;
  }
  if ((decl->flags2c & 4) == 0) {
    pcVar2 = decl->sym->type;
    iVar3 = type_size(pcVar2);
    if (iVar3 != 0) {
      type_check_based_allocation_fragment();
      return;
    }
    if (((undefined1)uVar1 & 7) != 1) {
      if ((pcVar2->code & 0x200) != 0) {
        tag_3 = (pcVar2->extra).sym;
        if ((tag_3->kind & 0x1f) != 4) {
          tag_3 = (tag_3->type->extra).sym;
        }
        if ((tag_3->flags1 & 1) == 0) {
          pcVar4 = decl->sym;
          if (pcVar4 == (c1_symbol *)0x0) {
            pcVar4 = sym_new_from_declarator(decl,3);
          }
          diag_error(0x4f,pcVar4,tag_3->type,tag_3);
          decl->sym->flags2 = decl->sym->flags2 | 1;
          return;
        }
      }
      tag = decl->sym;
      if (tag == (c1_symbol *)0x0) {
        tag = sym_new_from_declarator(decl,3);
      }
      diag_error(0x85,tag);
      type_check_based_allocation_fragment();
      return;
    }
  }
code_r0x10607ba6:
  return;
}

