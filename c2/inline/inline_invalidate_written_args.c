int __fastcall
inline_invalidate_written_args(c2_tuple *body,c2_inline_binding *bindings,c2_tuple **first_return)

{
  uint8_t uVar1;
  byte bVar2;
  char cVar3;
  uint32_t uVar4;
  c2_operand *pcVar5;
  c2_operand *pcVar6;
  c2_symbol *pcVar7;
  c2_symbol *pcVar8;
  c2_inline_binding **ppcVar9;
  c2_inline_binding *pcVar10;
  int iVar11;
  c2_symbol *node;
  uint uVar12;
  int iVar13;
  c2_tuple *pcVar14;
  int local_28;
  c2_tuple *local_24;
  c2_tuple *local_20;
  int local_1c;
  c2_tuple *local_18;
  int local_14;
  c2_tuple *local_8;
  c2_tuple *local_4;
  
  pcVar14 = (c2_tuple *)0x0;
  iVar13 = 0;
  local_1c = 0;
  local_18 = (c2_tuple *)0x0;
  local_20 = (c2_tuple *)0x0;
  local_14 = 0;
  for (pcVar10 = bindings; local_28 = iVar13, local_24 = body, pcVar10 != (c2_inline_binding *)0x0;
      pcVar10 = pcVar10->next) {
    if (pcVar10->value != (c2_operand *)0x0) {
      iVar13 = iVar13 + 1;
    }
  }
  do {
    if ((local_24->flags & 1) == 0) {
      if ((local_24->kind == '\x1a') && (pcVar14 != (c2_tuple *)0x0)) {
        local_14 = local_14 + 1;
      }
      goto LAB_107515f3;
    }
    uVar4 = local_24->op;
    if (uVar4 == 0x16c) {
      local_1c = local_1c + 1;
      if (pcVar14 == (c2_tuple *)0x0) {
        pcVar14 = local_24;
        local_18 = local_24;
      }
LAB_10751595:
      pcVar10 = bindings;
      if (0 < iVar13) {
        for (; pcVar10 != (c2_inline_binding *)0x0; pcVar10 = pcVar10->next) {
          pcVar5 = pcVar10->value;
          if (pcVar5 != (c2_operand *)0x0) {
            uVar1 = pcVar5->kind;
            if (uVar1 == '\x01') {
              iVar11 = inline_tree_may_write(local_24,pcVar5);
            }
            else {
              if (uVar1 != '\x02') {
                if ((uVar1 == '\x06') &&
                   ((iVar11 = inline_tuple_may_write(local_24,pcVar5), iVar11 != 0 ||
                    (((pcVar5 = pcVar10->value->base, iVar13 = local_28,
                      (1 << (pcVar5->kind & 0x1f) & 6U) != 0 &&
                      (pcVar5->sym->def != (c2_tuple *)0x0)) &&
                     (iVar11 = inline_tree_may_write(local_24,pcVar5), iVar11 != 0)))))) {
                  node_free((c2_node *)pcVar10->value);
                  local_28 = iVar13 + -1;
                  pcVar10->value = (c2_operand *)0x0;
                  iVar13 = local_28;
                }
                goto LAB_1075170c;
              }
              iVar11 = inline_tuple_may_write(local_24,pcVar5);
            }
            if (iVar11 != 0) {
              node_free((c2_node *)pcVar10->value);
              local_28 = iVar13 + -1;
              pcVar10->value = (c2_operand *)0x0;
              iVar13 = local_28;
            }
          }
LAB_1075170c:
        }
        for (pcVar5 = local_24->dst; pcVar5 != (c2_operand *)0x0; pcVar5 = pcVar5->next) {
          if ((pcVar5->kind == '\x02') && (pcVar5->sym->cls == '\x05')) {
            pcVar7 = pcVar5->sym->storage;
            if ((pcVar7->u18).expr != (c2_cse_expr *)0x0) {
              pcVar7 = pcVar7->order_next;
              pcVar8 = pcVar7->part_next;
joined_r0x10794182:
              if (pcVar8 != (c2_symbol *)0x0) {
                node_free((c2_node *)pcVar8);
                pcVar7->part_next = (c2_symbol *)0x0;
                iVar13 = iVar13 + -1;
              }
            }
          }
          else if (((pcVar5->kind == '\x06') &&
                   (((pcVar5->flags & 0x40) != 0 && (pcVar5->base->kind == '\x02')))) &&
                  (pcVar7 = pcVar5->base->sym, pcVar7->cls == '\x05')) {
            pcVar7 = pcVar7->storage->order_next;
            pcVar8 = pcVar7->part_next;
            goto joined_r0x10794182;
          }
          local_28 = iVar13;
        }
        pcVar5 = local_24->src;
        iVar13 = local_28;
        for (pcVar6 = pcVar5; pcVar14 = local_18, local_28 = iVar13, pcVar6 != (c2_operand *)0x0;
            pcVar6 = pcVar6->next) {
          if (((pcVar6->kind == '\x02') && (pcVar7 = pcVar6->sym, pcVar7->cls == '\x05')) &&
             ((pcVar7->storage->u18).expr != (c2_cse_expr *)0x0)) {
            pcVar8 = pcVar7->storage->order_next;
            node = pcVar8->part_next;
            if (node != (c2_symbol *)0x0) {
              if ((pcVar6->flags & 0x40) == 0) {
                bVar2 = *(byte *)&node->storage;
                uVar12 = 1 << (bVar2 & 0x1f);
                if ((uVar12 & 0x380) == 0) {
                  if ((uVar12 & 0x18) == 0) {
                    if ((bVar2 != 2) &&
                       (((node->part_next != (c2_symbol *)0x0 || (pcVar7->offset != 0)) ||
                        (((pcVar6->flags & 0x20) != 0 && (bVar2 == 6))))))
                    goto switchD_107941c8_caseD_2;
                  }
                  else {
                    if (((1 << (byte)(pcVar6->type >> 0xc) & 0xeU) == 0) ||
                       ((pcVar6->type & 0xfff) != 4)) {
                      node_free((c2_node *)node);
                      pcVar8->part_next = (c2_symbol *)0x0;
                      local_28 = iVar13 + -1;
                    }
                    if ((local_20 != (c2_tuple *)0x0) &&
                       ((local_24->op != 1 ||
                        ((*(char *)&pcVar8->part_next->storage == '\x03' &&
                         ((((cVar3 = (char)pcVar8->part_next->def->op, cVar3 == '\x03' ||
                            (cVar3 == '\x04')) || (cVar3 == '\x05')) || (cVar3 == '\x06')))))))) {
                      node = pcVar8->part_next;
LAB_10751838:
                      node_free((c2_node *)node);
                      pcVar8->part_next = (c2_symbol *)0x0;
                      local_28 = local_28 + -1;
                    }
                  }
                }
                else {
                  if ((((*(uint16_t *)((int)&node->storage + 2) ^ pcVar6->type) & 0xf000) != 0) ||
                     (pcVar7->offset != 0)) goto switchD_107941c8_caseD_2;
                  if (local_20 == (c2_tuple *)0x0) goto switchD_107941c8_caseD_1;
                  if ((local_24->type & 0xf000) == 0x4000) {
switchD_107941c8_caseD_2:
                    goto LAB_10751838;
                  }
                  switch(local_24->op) {
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
                    if (pcVar6 != pcVar5->next) goto switchD_107941c8_caseD_2;
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
          iVar13 = local_28;
        }
      }
    }
    else {
      if (uVar4 == 0x191) {
        local_20 = local_24->next;
        local_24 = (local_24->u20).default_label;
        goto LAB_10751595;
      }
      if (uVar4 != 0x1a0) {
        if (uVar4 == 0x1ab) {
          inline_invalidate_written_args((local_24->u20).default_label,bindings,&local_4);
          iVar13 = 0;
          local_28 = 0;
          pcVar10 = bindings;
          if (bindings == (c2_inline_binding *)0x0) goto LAB_107515f3;
          do {
            if (pcVar10->value != (c2_operand *)0x0) {
              iVar13 = iVar13 + 1;
            }
            ppcVar9 = &pcVar10->next;
            pcVar10 = *ppcVar9;
            local_28 = iVar13;
          } while (*ppcVar9 != (c2_inline_binding *)0x0);
        }
        goto LAB_10751595;
      }
      inline_invalidate_written_args
                (((local_24->u20).eh_construct)->object->funclet->cfg->first->head,bindings,&local_8
                );
      iVar13 = 0;
      local_28 = 0;
      pcVar10 = bindings;
      if (bindings != (c2_inline_binding *)0x0) {
        do {
          if (pcVar10->value != (c2_operand *)0x0) {
            iVar13 = iVar13 + 1;
          }
          pcVar10 = pcVar10->next;
          local_28 = iVar13;
        } while (pcVar10 != (c2_inline_binding *)0x0);
        goto LAB_10751595;
      }
    }
LAB_107515f3:
    local_24 = local_24->next;
    if (local_24 == (c2_tuple *)0x0) {
      if (local_20 == (c2_tuple *)0x0) {
        *first_return = pcVar14;
        if (1 < local_14) {
          local_1c = local_1c + 1;
        }
        return local_1c;
      }
      local_24 = local_20;
      local_20 = (c2_tuple *)0x0;
    }
  } while( true );
}

