int __fastcall
switch_narrow_int64_selector
          (c2_switch_case_range *cases,c2_tuple *selector_copy,int ncases,c2_tuple *default_label)

{
  int iVar1;
  uint32_t lo;
  int32_t hi;
  uint32_t lo_00;
  int32_t hi_00;
  c2_symbol *sym;
  c2_operand *src;
  c2_switch_case_range *pcVar2;
  c2_operand *pcVar3;
  c2_tuple *pcVar4;
  c2_tuple *pcVar5;
  c2_const_operand *pcVar6;
  uint uVar7;
  uint uVar8;
  uint16_t uVar9;
  int iVar10;
  bool bVar11;
  code *insert_fn_00;
  c2_insert_fn *insert_fn;
  
  if ((((selector_copy->op == 0x15b) &&
       (pcVar3 = selector_copy->dst, (1 << (pcVar3->kind & 0x1f) & 6U) != 0)) &&
      (pcVar3->sym->cls == '\x03')) &&
     (((selector_copy->type & 0xfff) == 8 &&
      (uVar7 = 0, pcVar2 = cases, cases != (c2_switch_case_range *)0x0)))) {
    do {
      if ((pcVar2->first_high <= pcVar2->last_high) &&
         ((pcVar2->first_high < pcVar2->last_high || (pcVar2->first < pcVar2->last)))) {
        uVar7 = uVar7 + 1;
      }
      pcVar2 = pcVar2->next;
      uVar7 = uVar7 + 1;
    } while (pcVar2 != (c2_switch_case_range *)0x0);
    if (3 < uVar7) {
      uVar7 = (uint)((pcVar3->type & 0xf000) == 0x1000);
      pcVar2 = cases;
      do {
        if (ncases == 0) {
          lo = cases->first;
          hi = cases->first_high;
          do {
            lo_00 = cases->last;
            hi_00 = cases->last_high;
            cases = cases->next;
          } while (cases != (c2_switch_case_range *)0x0);
          uVar9 = (-(ushort)(uVar7 != 0) & 0xf000) + 0x2004;
          pcVar3 = operand_new_temp_sym(selector_copy->src->type);
          pcVar4 = tuple_new_unary_temp(0x15f,uVar9,pcVar3,tuple_insert_before,selector_copy);
          sym = pcVar4->dst->sym;
          if (sym->storage->part_next == (c2_symbol *)0x0) {
            sym->def = pcVar4;
          }
          else {
            symbol_mark_overlapping_parts(sym,pcVar4);
          }
          src = selector_copy->src;
          pcVar5 = tuple_new(0x15b,pcVar3->type,pcVar3,src,tuple_insert_before,pcVar4);
          tuple_replace_src(selector_copy,src,pcVar4->dst);
          operand_set_type(selector_copy->dst,uVar9);
          selector_copy->type = uVar9;
          pcVar4 = pcVar5->next;
          if (uVar7 != 0) {
            uVar9 = pcVar3->type;
            insert_fn = tuple_insert_before;
            pcVar5 = pcVar4;
            pcVar6 = operand_new_intconst(uVar9,lo,hi);
            pcVar5 = tuple_new_compare(0x17d,uVar9,pcVar3,pcVar6,insert_fn,pcVar5);
            tuple_new_branch(0x185,'\x03',(c2_node *)default_label,pcVar5->dst,pcVar5,
                             tuple_insert_before,pcVar4);
          }
          uVar9 = pcVar3->type;
          insert_fn_00 = tuple_insert_before;
          pcVar5 = pcVar4;
          pcVar6 = operand_new_intconst(uVar9,lo_00,hi_00);
          pcVar5 = tuple_new_compare(0x17d,uVar9,pcVar3,pcVar6,insert_fn_00,pcVar5);
          tuple_new_branch(0x185,'\x04',(c2_node *)default_label,pcVar5->dst,pcVar5,
                           tuple_insert_before,pcVar4);
          return uVar7;
        }
        ncases = ncases + -1;
        iVar10 = pcVar2->first_high;
        iVar1 = pcVar2->last_high;
        uVar8 = pcVar2->first;
        if (iVar10 <= iVar1) {
          if (iVar10 < iVar1) goto LAB_10791ea9;
          do {
            if (pcVar2->last < uVar8) break;
LAB_10791ea9:
            do {
              if (uVar7 == 0) {
                if (iVar10 != 0) {
                  return 0;
                }
              }
              else if (iVar10 != (int)uVar8 >> 0x1f) {
                return 0;
              }
              bVar11 = 0xfffffffe < uVar8;
              uVar8 = uVar8 + 1;
              iVar10 = iVar10 + (uint)bVar11;
            } while (iVar10 < iVar1);
          } while (iVar10 <= iVar1);
        }
        pcVar2 = pcVar2->next;
      } while( true );
    }
  }
  return 0;
}

