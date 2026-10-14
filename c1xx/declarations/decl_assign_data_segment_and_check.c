void __fastcall decl_assign_data_segment_and_check(c1_declarator *d)

{
  uint storage;
  c1_type *pcVar1;
  uint uVar2;
  int iVar3;
  c1_type *pcVar4;
  c1_symbol *cls_tag_2;
  c1_symbol *pcVar5;
  c1_symbol *cls_tag;
  c1_symbol *cls_tag_3;
  c1_declarator *cls;
  
  if ((d->flags55 & 4) == 0) {
    cls_tag_2 = d->sym;
    storage._0_1_ = cls_tag_2->storage;
    storage._1_1_ = cls_tag_2->flags21;
    storage._2_1_ = cls_tag_2->flags22;
    storage._3_1_ = cls_tag_2->flags23;
    cls = d;
    switch(storage & 7) {
    case 1:
      if ((d->flags54 & 4) == 0) {
        return;
      }
    case 2:
    case 3:
      pcVar1 = type_skip_arrays(cls_tag_2->type);
      if (((byte)pcVar1->flags >> 5 & 1) == 0) {
        if ((cls_tag_2->flags4 & 4) == 0) {
          sym_set_segment_from(cls_tag_2,g_bss_seg_name);
        }
        else {
          sym_set_segment_from(cls_tag_2,g_data_seg_name);
        }
      }
      else {
        sym_set_segment_from(cls_tag_2,g_const_seg_name);
      }
      break;
    case 4:
    case 5:
    case 6:
      if ((cls_tag_2->flags23 & 1) != 0) {
        if (cls_tag_2 == (c1_symbol *)0x0) {
          cls_tag_2 = sym_new_from_declarator(d,5);
        }
        diag_error(0xb9,cls_tag_2);
      }
      break;
    case 7:
      goto code_r0x104069da;
    }
    type_check_destructible(d->sym);
    if ((d->flags54 & 4) == 0) {
      pcVar1 = d->sym->type;
      uVar2 = type_classify_class_form(pcVar1,(int *)&stack0xfffffffc);
      if (((uVar2 & 3) != 0) &&
         (pcVar4 = type_skip_arrays_and_functions(pcVar1), ((byte)pcVar4->flags >> 5 & 1) != 0)) {
        decl_check_const_auto_initialization(d,pcVar1,storage,(c1_symbol *)cls);
        return;
      }
      iVar3 = type_size(pcVar1);
      if (iVar3 != 0) {
        type_check_based_allocation_return_case();
        return;
      }
      if (((undefined1)storage & 7) != 1) {
        if ((pcVar1->code & 0x200) != 0) {
          cls_tag_3 = (pcVar1->extra).cls;
          if ((cls_tag_3->kind & 0x1f) != 4) {
            cls_tag_3 = (cls_tag_3->type->extra).cls;
          }
          if ((cls_tag_3->flags2 & 4) == 0) {
            pcVar5 = d->sym;
            if (pcVar5 == (c1_symbol *)0x0) {
              pcVar5 = sym_new_from_declarator(d,5);
            }
            diag_error(0x4f,pcVar5,cls_tag_3->type,cls_tag_3);
            d->sym->flags3 = d->sym->flags3 | 4;
            return;
          }
        }
        cls_tag = d->sym;
        if (cls_tag == (c1_symbol *)0x0) {
          cls_tag = sym_new_from_declarator(d,5);
        }
        diag_error(0x85,cls_tag);
        type_check_based_allocation_return_case();
        return;
      }
    }
  }
code_r0x104069da:
  return;
}

