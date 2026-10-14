int __fastcall sched_break_dep_by_displacement(c2_sched_edge *edge)

{
  uint16_t *puVar1;
  uint8_t uVar2;
  c2_sched_node *pcVar3;
  c2_tuple *a;
  c2_tuple *b;
  c2_sched_node *from;
  uint32_t uVar4;
  c2_operand *pcVar5;
  int iVar6;
  c2_sched_edge *pcVar7;
  c2_sched_edge *pcVar8;
  byte bVar9;
  c2_operand *pcVar10;
  byte bVar11;
  c2_symbol *pcVar12;
  c2_symbol *local_c;
  c2_sched_node *local_8;
  c2_sched_node *local_4;
  
  local_8 = edge->from;
  pcVar3 = edge->to;
  a = pcVar3->tuple;
  b = local_8->tuple;
  if (((local_8->sflags & 8) == 0) && ((pcVar3->sflags & 8) == 0)) {
    local_4 = pcVar3;
    if ((edge->type & 1) == 0) {
      if ((edge->type & 2) != 0) {
        switch(a->op) {
        case 0x12:
          pcVar5 = sched_find_breakable_mem_dep(a,b,&local_c);
          if (pcVar5 == (c2_operand *)0x0) {
            return 0;
          }
          pcVar10 = a->src;
          if (pcVar10 == (c2_operand *)0x0) {
            return 0;
          }
          while (pcVar10->kind != '\x05') {
            pcVar10 = pcVar10->next;
            if (pcVar10 == (c2_operand *)0x0) {
              return 0;
            }
          }
          if (pcVar10 == (c2_operand *)0x0) {
            return 0;
          }
          if (pcVar10->base_sym != (c2_symbol *)0x0) {
            return 0;
          }
          if ((pcVar10->op == 0x14c) && ((pcVar10->base->u18).reg == local_c)) {
            iVar6 = pcVar10->disp;
            edge->soft = edge->soft & 0xf3 | 0x13;
            pcVar12 = (c2_symbol *)-iVar6;
          }
          else {
            if (pcVar10->op != 0x14f) {
              return 0;
            }
            if ((pcVar10->index->u18).reg != local_c) {
              return 0;
            }
            if ((pcVar10->flags & 0xf) != 0) {
              return 0;
            }
            iVar6 = pcVar10->disp;
            edge->soft = edge->soft & 0xf4 | 0x14;
            pcVar12 = (c2_symbol *)-iVar6;
          }
          break;
        default:
          goto switchD_1073ba53_caseD_13;
        case 0x1e:
          pcVar5 = sched_find_breakable_mem_dep(a,b,&local_c);
          if (pcVar5 == (c2_operand *)0x0) {
            return 0;
          }
          pcVar12 = (c2_symbol *)0x1;
          edge->soft = edge->soft & 0xf6 | 0x16;
          local_4 = pcVar3;
          break;
        case 0x21:
          pcVar5 = sched_find_breakable_mem_dep(a,b,&local_c);
          if (pcVar5 == (c2_operand *)0x0) {
            return 0;
          }
          if ((a->dst->kind == '\x01') && (((a->dst->u18).reg)->id == 5)) {
            return 0;
          }
          pcVar12 = (c2_symbol *)0xffffffff;
          edge->soft = edge->soft & 0xf5 | 0x15;
          local_4 = pcVar3;
          break;
        case 0x2d:
          pcVar5 = sched_find_breakable_mem_dep(a,b,&local_c);
          if (pcVar5 == (c2_operand *)0x0) {
            return 0;
          }
          if ((a->dst->kind == '\x01') && (((a->dst->u18).reg)->id == 5)) {
            return 0;
          }
          pcVar10 = a->src->next;
          if (pcVar10->kind != '\a') {
            return 0;
          }
          uVar4 = (pcVar10->u18).lo;
          edge->soft = edge->soft & 0xf0 | 0x10;
          pcVar12 = (c2_symbol *)-uVar4;
          local_4 = pcVar3;
          break;
        case 0x32:
          pcVar5 = sched_find_breakable_mem_dep(a,b,&local_c);
          if (pcVar5 == (c2_operand *)0x0) {
            return 0;
          }
          pcVar10 = a->src->next;
          if (pcVar10->kind != '\a') {
            return 0;
          }
          pcVar12 = (pcVar10->u18).reg;
          edge->soft = edge->soft & 0xf1 | 0x11;
          local_4 = pcVar3;
        }
        if ((local_c != g_reg_symbols + 5) || (-1 < (int)&pcVar12->fe + pcVar5->disp)) {
          if ((g_opt_favor_speed == 0) &&
             (((edge->soft & 0x1f) == 0x12 ||
              (((pcVar5->base_sym == (c2_symbol *)0x0 && (pcVar5->disp == 0)) &&
               (pcVar12 != (c2_symbol *)0x0)))))) {
            edge->soft = edge->soft & 0xe0;
            return 0;
          }
          if ((edge->type & 4) == 0) {
            bVar9 = edge->soft;
            local_4->soft_preds = local_4->soft_preds + 1;
            edge->soft = bVar9 & 0xdf;
            return 1;
          }
          edge->soft = edge->soft & 0xe0;
        }
      }
    }
    else {
      switch(b->op) {
      case 0x12:
        pcVar5 = sched_find_breakable_mem_dep(b,a,&local_c);
        if (((pcVar5 != (c2_operand *)0x0) && (pcVar5->base_sym == (c2_symbol *)0x0)) &&
           (pcVar10 = b->src, pcVar10 != (c2_operand *)0x0)) {
          while (pcVar10->kind != '\x05') {
            pcVar10 = pcVar10->next;
            if (pcVar10 == (c2_operand *)0x0) {
              return 0;
            }
          }
          if (pcVar10 != (c2_operand *)0x0) {
            if ((pcVar5->op == 0x14c) || ((pcVar5->op == 0x14f && ((pcVar5->flags & 0xf) == 0)))) {
              edge->soft = edge->soft & 0xe5 | 5;
            }
            else if ((pcVar5->base == (c2_operand *)0x0) || ((pcVar5->base->u18).reg != local_c)) {
              if (pcVar10->op == 0x14c) {
                bVar9 = 0;
              }
              else if (pcVar10->op == 0x14f) {
                bVar9 = pcVar10->flags & 0xf;
              }
              else {
                bVar9 = 99;
              }
              if (3 < (byte)(bVar9 + (pcVar5->flags & 0xf))) {
                return 0;
              }
              edge->soft = edge->soft & 0xe9 | 9;
            }
            else {
              if (pcVar10->op != 0x14c) {
                if (pcVar10->op != 0x14f) {
                  return 0;
                }
                if ((pcVar10->flags & 0xf) != 0) {
                  return 0;
                }
              }
              edge->soft = edge->soft & 0xe7 | 7;
            }
            iVar6 = 0;
            goto LAB_1073bbf5;
          }
        }
        break;
      case 0x1e:
        pcVar5 = sched_find_breakable_mem_dep(b,a,&local_c);
        if ((pcVar5 != (c2_operand *)0x0) &&
           ((b->dst->kind != '\x01' || (((b->dst->u18).reg)->id != 5)))) {
          edge->soft = edge->soft & 0xec | 0xc;
          iVar6 = 0x107adcd8;
LAB_1073bbf5:
          iVar6 = return0_stdcall2((int)local_c,iVar6);
          pcVar3 = local_4;
          bVar9 = edge->soft;
          bVar11 = ((byte)iVar6 & 1) << 5 | bVar9 & 0xdf;
          edge->soft = bVar11;
          if ((iVar6 == 0) && ((edge->type & 6) != 0)) {
            if (b->op == 0x12) {
              pcVar5 = b->src->base;
              if (((pcVar5 == (c2_operand *)0x0) || ((pcVar5->u18).reg != local_c)) &&
                 ((pcVar5 = b->src->index, pcVar5 == (c2_operand *)0x0 ||
                  ((pcVar5->u18).reg != local_c)))) {
                pcVar7 = sched_add_edge(local_8,local_4,edge->type & 0xfffffffe);
                if ((pcVar7->type & 4) != 0) {
                  pcVar7->latency = 1;
                }
                puVar1 = &edge->to->soft_preds;
                *puVar1 = *puVar1 + 1;
                edge->type = 1;
                edge->soft = (bVar11 + 1 ^ bVar11) & 0x1f ^ bVar11;
                return 1;
              }
            }
            edge->soft = bVar9 & 0xc0;
            return 0;
          }
          pcVar7 = local_8->preds;
          do {
            if (pcVar7 == (c2_sched_edge *)0x0) {
              puVar1 = &edge->to->soft_preds;
              *puVar1 = *puVar1 + 1;
              return 1;
            }
            if ((pcVar7->type & 1) == 0) {
LAB_1073bc41:
              if ((pcVar7->type & 0x80000) != 0) {
                sched_add_or_merge_edge(pcVar7->from,pcVar3,0x80000);
              }
            }
            else {
              from = pcVar7->from;
              pcVar8 = sched_find_edge(from,pcVar3);
              if (pcVar8 != (c2_sched_edge *)0x0) goto LAB_1073bc41;
              pcVar8 = sched_add_edge(from,pcVar3,1);
              pcVar8->latency = edge->latency;
            }
            pcVar7 = pcVar7->next_pred;
          } while( true );
        }
        break;
      case 0x21:
        pcVar5 = sched_find_breakable_mem_dep(b,a,&local_c);
        if (pcVar5 != (c2_operand *)0x0) {
          edge->soft = edge->soft & 0xeb | 0xb;
          iVar6 = 0x107adcd8;
          goto LAB_1073bbf5;
        }
        break;
      case 0x22:
        pcVar5 = sched_find_breakable_mem_dep(b,a,&local_c);
        if ((pcVar5 != (c2_operand *)0x0) && (pcVar10 = b->src->next, pcVar10->kind == '\a')) {
          uVar4 = (pcVar10->u18).lo;
          if ((pcVar5->index == (c2_operand *)0x0) &&
             ((((uVar4 == 1 || (uVar4 == 2)) || (uVar4 == 4)) || (uVar4 == 8)))) {
            edge->soft = edge->soft & 0xe4 | 4;
            iVar6 = 0x107adcd8;
          }
          else {
            if (pcVar5->base != (c2_operand *)0x0) {
              return 0;
            }
            iVar6 = (1 << (pcVar5->flags & 0xf)) * uVar4;
            if (((iVar6 == 1) || (iVar6 == 2)) || ((iVar6 == 4 || (iVar6 == 8)))) {
              edge->soft = edge->soft & 0xe4 | 4;
            }
            iVar6 = 0x107adcd8;
          }
          goto LAB_1073bbf5;
        }
        break;
      case 0x2d:
        pcVar5 = sched_find_breakable_mem_dep(b,a,&local_c);
        if (pcVar5 != (c2_operand *)0x0) {
          uVar2 = b->src->next->kind;
          if (uVar2 == '\a') {
            edge->soft = edge->soft & 0xe1 | 1;
            iVar6 = 0x107adcd8;
          }
          else {
            if (uVar2 != '\x01') {
              return 0;
            }
            if (pcVar5->op == 0x14c) {
              iVar6 = 0x107adcd8;
              edge->soft = edge->soft & 0xe2 | 2;
            }
            else {
              if (pcVar5->op != 0x14f) {
                return 0;
              }
              if ((pcVar5->flags & 0xf) != 0) {
                return 0;
              }
              iVar6 = 0x107adcd8;
              edge->soft = edge->soft & 0xe2 | 2;
            }
          }
          goto LAB_1073bbf5;
        }
        break;
      case 0x32:
        pcVar5 = sched_find_breakable_mem_dep(b,a,&local_c);
        if (((pcVar5 != (c2_operand *)0x0) &&
            ((b->dst->kind != '\x01' || (((b->dst->u18).reg)->id != 5)))) &&
           (b->src->next->kind == '\a')) {
          iVar6 = 0x107adcd8;
          edge->soft = edge->soft & 0xe3 | 3;
          goto LAB_1073bbf5;
        }
      }
    }
  }
switchD_1073ba53_caseD_13:
  return 0;
}

