c2_operand * __fastcall find_available_copy_source(c2_tuple *t,c2_operand *opnd)

{
  ushort uVar1;
  ushort uVar2;
  c2_symbol *a;
  c2_symbol_cell *pcVar3;
  c2_symbol *pcVar4;
  int iVar5;
  uint32_t uVar6;
  c2_operand *pcVar7;
  c2_symbol *pcVar8;
  uint8_t count;
  uint uVar9;
  c2_operand *a_00;
  longlong lVar10;
  uint64_t uVar11;
  c2_symbol *copy_expr_sym;
  
  if ((1 << (opnd->kind & 0x1f) & 6U) == 0) {
    if (opnd->kind != 6) {
      return (c2_operand *)0x0;
    }
    pcVar8 = (opnd->u18).reg;
  }
  else {
    pcVar8 = opnd->sym;
  }
  if (pcVar8 == (c2_symbol *)0x0) {
    return (c2_operand *)0x0;
  }
  iVar5 = node_has_side_effects((c2_node *)opnd);
  if (iVar5 != 0) {
    return (c2_operand *)0x0;
  }
  if ((opnd->flags9 & 8) != 0) {
    return (c2_operand *)0x0;
  }
  if (t->flags13 == '\x11') {
    return (c2_operand *)0x0;
  }
  a = pcVar8->storage;
  do {
    if (a == (c2_symbol *)0x0) {
      return (c2_operand *)0x0;
    }
    if ((a->offset <= pcVar8->offset) && (pcVar8->size + pcVar8->offset <= a->size + a->offset)) {
      for (pcVar3 = a->copy_equivs; pcVar3 != (c2_symbol_cell *)0x0; pcVar3 = pcVar3->next) {
        copy_expr_sym = pcVar3->sym;
        if ((copy_expr_sym->def == (c2_tuple *)0x0) &&
           (uVar6 = bitset_test(g_cur_avail_set,copy_expr_sym->id), uVar6 != 0)) {
          pcVar7 = ((copy_expr_sym->u18).expr)->operands->next;
          iVar5 = node_has_side_effects((c2_node *)pcVar7);
          if (iVar5 != 0) {
            return (c2_operand *)0x0;
          }
          if ((((g_in_iv_optimization != 0) && ((1 << (pcVar7->kind & 0x1f) & 6U) != 0)) &&
              (uVar6 = is_induction_variable_operand(pcVar7), uVar6 != 0)) &&
             (iVar5 = operand_is_partial_alias_iv(opnd), iVar5 != 0)) {
            return (c2_operand *)0x0;
          }
          if ((((1 << (opnd->kind & 0x1f) & 6U) != 0) && (opnd->sym->cls == '\x03')) &&
             ((opnd->type & 0xf000) == 0x5000)) goto LAB_1070eb50;
          if (t->op == 0x15b) {
            if (((t->type & 0xf000) == 0x5000) &&
               (iVar5 = operands_may_alias(t->dst,pcVar7), iVar5 != 0)) {
              return (c2_operand *)0x0;
            }
            if (((t->op == 0x15b) && ((t->type & 0xf000) != 0x5000)) &&
               ((iVar5 = operand_compare(t->dst,pcVar7), iVar5 == 0 ||
                (uVar6 = is_store_of_same_loaded_value(t,pcVar7), uVar6 != 0)))) goto LAB_1070eb50;
          }
          if (((((1 << (pcVar7->kind & 0x1f) & 6U) != 0) &&
               (copy_expr_sym = pcVar7->sym, copy_expr_sym->cls == '\x03')) &&
              (((g_propagate_temp_copies == 0 ||
                (((((1 << (opnd->kind & 0x1f) & 6U) == 0 ||
                   (pcVar4 = opnd->sym, pcVar4->cls != '\x03')) ||
                  (((pcVar4->u30).sizeopt.width_facts & 1) != 0)) ||
                 (((copy_expr_sym->flags7 ^ pcVar4->flags7) & 2) != 0)))) &&
               ((((copy_expr_sym->u30).sizeopt.width_facts & 3) == 0 ||
                ((pcVar8->dependents != (c2_bitset *)0x0 &&
                 (uVar6 = bitset_test(pcVar8->dependents,copy_expr_sym->id), uVar6 != 0)))))))) &&
             (((opnd->kind != '\x06' || (iVar5 = type_is_register_candidate(opnd->type), iVar5 == 0)
               ) && (((pcVar8->u18).expr == (c2_cse_expr *)0x0 ||
                     (((pcVar8->u18).expr)->op != 0x15d)))))) {
            if (t->op != 0x17d) {
              return (c2_operand *)0x0;
            }
            a_00 = t->src;
            if (a_00 == (c2_operand *)0x0) {
              return (c2_operand *)0x0;
            }
            while (iVar5 = operand_compare(a_00,pcVar7), iVar5 != 0) {
              a_00 = a_00->next;
              if (a_00 == (c2_operand *)0x0) {
                return (c2_operand *)0x0;
              }
            }
          }
          uVar9 = 1 << (pcVar7->kind & 0x1f);
          if ((((uVar9 & 0x60) == 0) ||
              ((((pcVar7->type & 0xf000) == 0x5000 && ((opnd->flags & 0x20) == 0)) &&
               (((opnd->type ^ pcVar7->type) & 0xfff) == 0)))) &&
             ((((uVar9 & 6) == 0 || (pcVar7->sym->cls != '\a')) || (pcVar8->cls == '\a')))) {
            uVar1 = pcVar7->type;
            uVar2 = opnd->type;
            if (uVar1 != uVar2) {
              if ((1 << (byte)(uVar1 >> 0xc) & 0xeU) == 0) {
                if ((uVar1 & 0xf000) != 0x5000) {
                  return (c2_operand *)0x0;
                }
                if ((uVar1 & 0xfff) < (uVar2 & 0xfff)) {
                  return (c2_operand *)0x0;
                }
              }
              else {
                if (((1 << (byte)(uVar2 >> 0xc) & 0xeU) == 0) && ((uVar2 & 0xf000) != 0x5000)) {
                  return (c2_operand *)0x0;
                }
                if ((uVar1 & 0xfff) < (uVar2 & 0xfff)) {
                  return (c2_operand *)0x0;
                }
              }
            }
            if (((((opnd->flags & 0x20) == 0) ||
                 (((uVar9 & 0x380) == 0 && (pcVar7->kind != '\x04')))) &&
                ((pcVar7->kind != '\a' ||
                 ((((uVar2 & 0xf000) != 0x4000 || ((uVar1 & 0xfff) < 5)) &&
                  ((uVar2 & 0xf000) != 0x5000)))))) &&
               (((t->flags13 != '\x02' || ((uVar9 & 0x380) == 0)) ||
                (((1 << (t->src->kind & 0x1f) & 0x380U) == 0 &&
                 ((1 << (t->src->next->kind & 0x1f) & 0x380U) == 0)))))) {
LAB_1070eb50:
              if ((g_opt_dlp == 0) ||
                 ((((opnd->flags & 0x20) == 0 || (pcVar7->kind != '\x03')) &&
                  (pcVar7->kind != '\x05')))) {
                if (((1 << (pcVar7->kind & 0x1f) & 6U) != 0) &&
                   (pcVar7->sym->def != (c2_tuple *)0x0)) {
                  cse_unlink_copy_chain(pcVar7->sym);
                }
                pcVar7 = (c2_operand *)node_clone((c2_node *)pcVar7);
                uVar9 = 1 << (pcVar7->kind & 0x1f);
                if ((uVar9 & 6) == 0) {
                  if (pcVar7->kind == 7) {
                    iVar5 = compare_field_24((int)a,(int)pcVar8);
                    if (iVar5 != 0) {
                      count = (char)iVar5 * '\b';
                      if ((pcVar8->type & 0xf000) == 0x1000) {
                        lVar10 = allshr((pcVar7->u18).lo,pcVar7->tag,count);
                        pcVar7->u18 = (c2_operand_u18)(int)lVar10;
                        pcVar7->tag = (int)((ulonglong)lVar10 >> 0x20);
                        return pcVar7;
                      }
                      uVar11 = aullshr(count,pcVar7->tag,(pcVar7->u18).lo);
                      pcVar7->u18 = (c2_operand_u18)(int)uVar11;
                      pcVar7->tag = (int)(uVar11 >> 0x20);
                      return pcVar7;
                    }
                  }
                  else if (((uVar9 & 0x18) != 0) && (((pcVar7->type ^ opnd->type) & 0xfff) != 0)) {
                    node_free((c2_node *)pcVar7);
                    pcVar7 = (c2_operand *)0x0;
                  }
                }
                else {
                  iVar5 = compare_field_24((int)a,(int)pcVar8);
                  pcVar8 = symbol_get_part(pcVar7->sym,pcVar8->type,pcVar8->size,iVar5);
                  pcVar7->sym = pcVar8;
                  if (((((1 << (pcVar7->kind & 0x1f) & 6U) != 0) && (pcVar8->cls == '\x03')) &&
                      ((1 << (opnd->kind & 0x1f) & 6U) != 0)) &&
                     ((opnd->sym->cls == '\x03' && ((opnd->sym->flags7 & 2) != 0)))) {
                    pcVar8->flags7 = pcVar8->flags7 | 2;
                    return pcVar7;
                  }
                }
                return pcVar7;
              }
            }
          }
          return (c2_operand *)0x0;
        }
      }
    }
    a = a->part_next;
  } while( true );
}

