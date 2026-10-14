int __fastcall sizeopt_forward_scan(c2_block *block)

{
  uint8_t *puVar1;
  uint8_t uVar2;
  ushort uVar3;
  c2_tuple *pcVar4;
  c2_symbol *pcVar5;
  c2_tuple *t;
  c2_operand *pcVar6;
  c2_tuple *pcVar7;
  uint32_t uVar8;
  int iVar9;
  int local_8;
  
  pcVar4 = block->end;
  local_8 = 0;
  t = block->head->next;
  do {
    if (t == pcVar4) {
      return local_8;
    }
    pcVar7 = t->next;
    switch(t->kind) {
    case '\r':
    case '\x0f':
    case '\x12':
    case '\x13':
    case '\x14':
    case '\x15':
    case '\x16':
    case '\x17':
    case '\x18':
    case '\x19':
    case '\x1a':
    case '\x1b':
      break;
    case '\x0e':
      if (t->dst != (c2_operand *)0x0) goto switchD_107190e0_default;
      break;
    case '\x10':
switchD_107190e0_caseD_10:
      uVar3 = t->line;
      if (uVar3 != 0) {
        g_current_line_abs = g_cur_function->line_base + (uint)uVar3;
        g_cur_line = uVar3;
      }
      if (t->kind == '\x11') {
        if (((t->u20).cond_cells != (c2_cond_cell *)0x0) || (t->op == 0x18b)) {
          pcVar6 = t->src->next;
          goto LAB_1071912b;
        }
      }
      else if (t->kind == '\x10') {
        pcVar6 = t->src;
LAB_1071912b:
        if (pcVar6 == (c2_operand *)0x0) goto LAB_10719317;
        uVar8 = sizeopt_branch_operands(t,pcVar6);
        if (uVar8 == 0) break;
LAB_10719142:
        local_8 = 1;
      }
      else {
LAB_10719317:
        uVar8 = t->op;
        if ((uVar8 == 0x15b) && ((1 << (t->dst->kind & 0x1f) & 6U) != 0)) {
          pcVar5 = t->dst->sym;
          uVar2 = pcVar5->cls;
          if (((uVar2 != '\x03') && (((uVar2 != '\x04' && (uVar2 != '\x05')) && (uVar2 != '\x06'))))
             || (((pcVar5->def != (c2_tuple *)0x0 ||
                  (pcVar6 = t->src, (1 << (pcVar6->kind & 0x1f) & 0x60U) == 0)) ||
                 ((t->type & 0xfff) != 2)))) goto LAB_10719326;
LAB_107191b1:
          pcVar7 = tuple_new_unary_temp(0x15b,t->type,pcVar6,tuple_insert_before,t);
          tuple_replace_src(t,t->src,pcVar7->dst);
        }
        else {
LAB_10719326:
          if ((((uVar8 == 0x172) || (uVar8 == 0x177)) &&
              ((pcVar6 = t->src, (1 << (pcVar6->kind & 0x1f) & 6U) == 0 ||
               (pcVar6->sym->def == (c2_tuple *)0x0)))) &&
             (((1 << (t->dst->kind & 0x1f) & 6U) != 0 && (t->dst->sym->def != (c2_tuple *)0x0))))
          goto LAB_107191b1;
        }
        if (((1 << (t->dst->kind & 0x1f) & 6U) != 0) && (t->dst->sym->def != (c2_tuple *)0x0)) {
          if ((t->type & 0xfff) < 2) break;
          uVar8 = sizeopt_tuple_leading_zeros(t);
          sizeopt_set_known_bits_of_parts(t,uVar8);
          iVar9 = is_word_zero_extend(t);
          if (iVar9 != 0) {
            puVar1 = &(t->dst->sym->u30).sizeopt.width_facts;
            *puVar1 = *puVar1 | 1;
          }
          iVar9 = is_byte_zero_extend(t);
          if (iVar9 != 0) {
            puVar1 = &(t->dst->sym->u30).sizeopt.width_facts;
            *puVar1 = *puVar1 | 2;
          }
        }
        if ((t->type & 0xfff) == 4) {
          if ((t->op == 0x15f) && (pcVar6 = t->src, pcVar6->type == 0x2002)) {
            if (((1 << (pcVar6->kind & 0x1f) & 6U) != 0) && (pcVar6->sym->def != (c2_tuple *)0x0)) {
              iVar9 = sizeopt_has_byte_def_at_least(pcVar6->sym,0x10);
joined_r0x10719437:
              if (iVar9 != 0) {
                remove_redundant_extension(t);
                goto LAB_10719142;
              }
            }
          }
          else if ((t->op == 0x15f) &&
                  (((pcVar6 = t->src, pcVar6->type == 0x2001 &&
                    ((1 << (pcVar6->kind & 0x1f) & 6U) != 0)) &&
                   (pcVar6->sym->def != (c2_tuple *)0x0)))) {
            iVar9 = sizeopt_has_byte_def_at_least(pcVar6->sym,0x18);
            goto joined_r0x10719437;
          }
        }
      }
      break;
    case '\x11':
      if ((t->flags & 8) == 0) goto switchD_107190e0_caseD_10;
      break;
    default:
switchD_107190e0_default:
      if ((t->type & 0xf000) != 0x4000) {
        if ((4 < (t->type & 0xfff)) && (t->op == 0x16f)) {
          sizeopt_mul_of_extends(t);
        }
        if (((t->type & 0xfff) < 5) &&
           (((pcVar6 = t->src, pcVar6 == (c2_operand *)0x0 || ((pcVar6->type & 0xfff) < 5)) &&
            ((pcVar6->type & 0xf000) != 0x4000)))) goto switchD_107190e0_caseD_10;
      }
    }
    t = pcVar7;
  } while( true );
}

