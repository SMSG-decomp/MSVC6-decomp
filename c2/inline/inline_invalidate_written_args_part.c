int inline_invalidate_written_args_part
              (c2_inline_binding *binding,c2_tuple *t,int count,int count_home,c2_tuple *cursor,
              c2_tuple *resume_after,int return_count,c2_tuple *first_return,int label_count,
              c2_inline_binding *bindings,c2_operand *src_list,c2_tuple *nested_return_a,
              c2_tuple *nested_return_b,c2_tuple **first_return_out)

{
  uint8_t uVar1;
  byte bVar2;
  char cVar3;
  uint32_t uVar4;
  c2_operand *pcVar5;
  c2_operand *pcVar6;
  c2_symbol *pcVar7;
  c2_symbol *pcVar8;
  c2_tuple *pcVar9;
  c2_inline_binding **ppcVar10;
  c2_inline_binding *pcVar11;
  int iVar12;
  c2_symbol *node;
  uint uVar13;
  c2_tuple *pcVar14;
  
code_r0x107516eb:
  node_free((c2_node *)binding->value);
  count_home = count + -1;
  binding->value = (c2_operand *)0x0;
  count = count_home;
LAB_1075170c:
  do {
    do {
      binding = binding->next;
      pcVar9 = cursor;
      while (pcVar14 = first_return, cursor = pcVar9, first_return = pcVar14,
            binding == (c2_inline_binding *)0x0) {
        for (pcVar6 = t->dst; pcVar6 != (c2_operand *)0x0; pcVar6 = pcVar6->next) {
          if ((pcVar6->kind == '\x02') && (pcVar6->sym->cls == '\x05')) {
            pcVar7 = pcVar6->sym->storage;
            if ((pcVar7->u18).expr != (c2_cse_expr *)0x0) {
              pcVar7 = pcVar7->order_next;
              pcVar8 = pcVar7->part_next;
joined_r0x10794182:
              if (pcVar8 != (c2_symbol *)0x0) {
                node_free((c2_node *)pcVar8);
                pcVar7->part_next = (c2_symbol *)0x0;
                count = count + -1;
              }
            }
          }
          else if ((pcVar6->kind == '\x06') &&
                  ((((pcVar6->flags & 0x40) != 0 && (pcVar6->base->kind == '\x02')) &&
                   (pcVar7 = pcVar6->base->sym, pcVar7->cls == '\x05')))) {
            pcVar7 = pcVar7->storage->order_next;
            pcVar8 = pcVar7->part_next;
            goto joined_r0x10794182;
          }
          count_home = count;
        }
        pcVar6 = t->src;
        count = count_home;
        cursor = t;
        for (pcVar5 = pcVar6; count_home = count, pcVar5 != (c2_operand *)0x0; pcVar5 = pcVar5->next
            ) {
          if (((pcVar5->kind == '\x02') && (pcVar7 = pcVar5->sym, pcVar7->cls == '\x05')) &&
             ((pcVar7->storage->u18).expr != (c2_cse_expr *)0x0)) {
            pcVar8 = pcVar7->storage->order_next;
            node = pcVar8->part_next;
            if (node != (c2_symbol *)0x0) {
              if ((pcVar5->flags & 0x40) == 0) {
                bVar2 = *(byte *)&node->storage;
                uVar13 = 1 << (bVar2 & 0x1f);
                if ((uVar13 & 0x380) == 0) {
                  if ((uVar13 & 0x18) == 0) {
                    if ((bVar2 != 2) &&
                       (((node->part_next != (c2_symbol *)0x0 || (pcVar7->offset != 0)) ||
                        (((pcVar5->flags & 0x20) != 0 && (bVar2 == 6))))))
                    goto switchD_107941c8_caseD_2;
                  }
                  else {
                    if (((1 << (byte)(pcVar5->type >> 0xc) & 0xeU) == 0) ||
                       ((pcVar5->type & 0xfff) != 4)) {
                      node_free((c2_node *)node);
                      pcVar8->part_next = (c2_symbol *)0x0;
                      count_home = count + -1;
                    }
                    if ((resume_after != (c2_tuple *)0x0) &&
                       ((pcVar9->op != 1 ||
                        ((*(char *)&pcVar8->part_next->storage == '\x03' &&
                         ((((cVar3 = (char)pcVar8->part_next->def->op, cVar3 == '\x03' ||
                            (cVar3 == '\x04')) || (cVar3 == '\x05')) || (cVar3 == '\x06')))))))) {
                      node = pcVar8->part_next;
LAB_10751838:
                      node_free((c2_node *)node);
                      pcVar8->part_next = (c2_symbol *)0x0;
                      count_home = count_home + -1;
                    }
                  }
                }
                else {
                  if ((((*(uint16_t *)((int)&node->storage + 2) ^ pcVar5->type) & 0xf000) != 0) ||
                     (pcVar7->offset != 0)) goto switchD_107941c8_caseD_2;
                  if (resume_after == (c2_tuple *)0x0) goto switchD_107941c8_caseD_1;
                  if ((pcVar9->type & 0xf000) == 0x4000) {
switchD_107941c8_caseD_2:
                    goto LAB_10751838;
                  }
                  switch(pcVar9->op) {
                  case 1:
                  case 0xd:
                    break;
                  default:
                    goto switchD_107941c8_caseD_2;
                  case 0x2c:
                  case 0x2d:
                  case 0x2e:
                  case 0x2f:
                  case 0x30:
                  case 0x31:
                  case 0x32:
                  case 0x34:
                    if (pcVar5 != pcVar6->next) goto switchD_107941c8_caseD_2;
                  }
                }
switchD_107941c8_caseD_1:
                if (pcVar8->part_next != (c2_symbol *)0x0) {
                  pcVar8->part_next->part_next = (c2_symbol *)0x1;
                }
              }
              else {
                pcVar8->part_next = (c2_symbol *)0x0;
              }
            }
          }
          count = count_home;
          cursor = pcVar9;
        }
LAB_107515f3:
        do {
          while( true ) {
            cursor = cursor->next;
            if (cursor == (c2_tuple *)0x0) {
              if (resume_after == (c2_tuple *)0x0) {
                *first_return_out = pcVar14;
                if (1 < label_count) {
                  return_count = return_count + 1;
                }
                return return_count;
              }
              cursor = resume_after;
              resume_after = (c2_tuple *)0x0;
            }
            if ((cursor->flags & 1) != 0) break;
            if ((cursor->kind == '\x1a') && (pcVar14 != (c2_tuple *)0x0)) {
              label_count = label_count + 1;
            }
          }
          uVar4 = cursor->op;
          if (uVar4 == 0x16c) {
            return_count = return_count + 1;
            if (pcVar14 == (c2_tuple *)0x0) {
              pcVar14 = cursor;
              first_return = cursor;
            }
          }
          else if (uVar4 == 0x191) {
            resume_after = cursor->next;
            cursor = (cursor->u20).default_label;
          }
          else if (uVar4 == 0x1a0) {
            inline_invalidate_written_args
                      (((cursor->u20).eh_construct)->object->funclet->cfg->first->head,bindings,
                       &nested_return_a);
            count = 0;
            count_home = 0;
            pcVar11 = bindings;
            if (bindings == (c2_inline_binding *)0x0) goto LAB_107515f3;
            do {
              if (pcVar11->value != (c2_operand *)0x0) {
                count = count + 1;
              }
              pcVar11 = pcVar11->next;
              count_home = count;
            } while (pcVar11 != (c2_inline_binding *)0x0);
          }
          else if (uVar4 == 0x1ab) {
            inline_invalidate_written_args((cursor->u20).default_label,bindings,&nested_return_b);
            count = 0;
            count_home = 0;
            pcVar11 = bindings;
            if (bindings == (c2_inline_binding *)0x0) goto LAB_107515f3;
            do {
              if (pcVar11->value != (c2_operand *)0x0) {
                count = count + 1;
              }
              ppcVar10 = &pcVar11->next;
              pcVar11 = *ppcVar10;
              count_home = count;
            } while (*ppcVar10 != (c2_inline_binding *)0x0);
          }
          binding = bindings;
          t = cursor;
          pcVar9 = cursor;
        } while (count < 1);
      }
      pcVar6 = binding->value;
    } while (pcVar6 == (c2_operand *)0x0);
    uVar1 = pcVar6->kind;
    if (uVar1 == '\x01') {
      iVar12 = inline_tree_may_write(t,pcVar6);
LAB_10751708:
      if (iVar12 != 0) {
        node_free((c2_node *)binding->value);
        count_home = count + -1;
        binding->value = (c2_operand *)0x0;
        count = count_home;
      }
      goto LAB_1075170c;
    }
    if (uVar1 == '\x02') {
      iVar12 = inline_tuple_may_write(t,pcVar6);
      goto LAB_10751708;
    }
    if ((uVar1 == '\x06') &&
       ((iVar12 = inline_tuple_may_write(t,pcVar6), iVar12 != 0 ||
        (((pcVar6 = binding->value->base, count = count_home, (1 << (pcVar6->kind & 0x1f) & 6U) != 0
          && (pcVar6->sym->def != (c2_tuple *)0x0)) &&
         (iVar12 = inline_tree_may_write(t,pcVar6), iVar12 != 0)))))) goto code_r0x107516eb;
  } while( true );
}

