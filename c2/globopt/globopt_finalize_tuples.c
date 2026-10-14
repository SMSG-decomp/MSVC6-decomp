void __fastcall globopt_finalize_tuples(c2_function *fn)

{
  c2_operand *pcVar1;
  bool bVar2;
  uint16_t uVar3;
  int iVar4;
  c2_operand *src;
  c2_tuple *pcVar5;
  c2_symbol *pcVar6;
  c2_tuple *pcVar7;
  c2_tuple *t;
  ushort uVar8;
  uint size;
  uint64_t uVar9;
  uint32_t local_10;
  c2_tuple *local_c;
  c2_function *local_8;
  c2_tuple *local_4;
  
  g_globopt_finalize_unread_flag = 0;
  local_4 = fn->cfg->last->end;
  t = fn->cfg->first->head->next;
  local_8 = fn;
  if (t != local_4) {
    do {
      local_c = t->next;
      if (t->line != 0) {
        g_current_line_abs = local_8->line_base + (uint)t->line;
        g_cur_line = t->line;
      }
      if (t->op == 0x169) {
        t->op = 0x15b;
      }
      if (t->op == 0x15b) {
        iVar4 = operand_compare(t->dst,t->src);
        if ((iVar4 != 0) || (iVar4 = node_has_side_effects((c2_node *)t), iVar4 != 0)) {
          if ((t->type & 0xf000) == 0x5000) {
            t->kind = '\r';
            t->op = 0x16b;
          }
          goto LAB_1071e3a6;
        }
        tuple_delete(t);
      }
      else {
LAB_1071e3a6:
        if ((t->flags & 1) != 0) {
          for (pcVar1 = t->src; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
            pcVar1->flags11 = pcVar1->flags11 & 0x7f;
            if ((1 << (pcVar1->kind & 0x1f) & 6U) == 0) {
              if (pcVar1->kind == 7) {
                if (((t->kind == '\f') && (t->op != 0x15f)) &&
                   ((iVar4 = op_is_div_like(t), iVar4 == 0 || (pcVar1 != t->src->next)))) {
                  uVar3 = t->type;
                }
                else {
                  uVar3 = pcVar1->type;
                }
                uVar9 = const_normalize(uVar3,(pcVar1->u18).lo,pcVar1->tag);
                pcVar1->u18 = (c2_operand_u18)(int)uVar9;
                pcVar1->tag = (int)(uVar9 >> 0x20);
                pcVar1->type = uVar3;
              }
              else if (((((1 << (pcVar1->kind & 0x1f) & 0x60U) != 0) && (t->kind == '\f')) &&
                       (t->op != 0x15f)) &&
                      ((iVar4 = op_is_div_like(t), iVar4 == 0 || (pcVar1 != t->src->next)))) {
                pcVar1->type = t->type;
              }
            }
            else {
              pcVar6 = pcVar1->sym;
              if (((t->kind == '\f') && ((pcVar1->flags & 0x20) == 0)) &&
                 ((t->op != 0x15f &&
                  ((iVar4 = op_is_div_like(t), iVar4 == 0 || (pcVar1 != t->src->next)))))) {
                uVar8 = t->type;
                pcVar1->type = uVar8;
              }
              else {
                uVar8 = pcVar1->type;
              }
              iVar4 = types_compatible(pcVar6->type,uVar8);
              if (iVar4 == 0) {
                pcVar6 = symbol_get_part(pcVar6,uVar8,uVar8 & 0xfff,0);
                pcVar1->sym = pcVar6;
              }
            }
          }
          for (pcVar1 = t->dst; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
            pcVar1->flags11 = pcVar1->flags11 & 0x7f;
            if ((pcVar1->kind == '\x02') &&
               (pcVar6 = pcVar1->sym, (pcVar6->u18).expr != (c2_cse_expr *)0x0)) {
              uVar8 = pcVar1->type;
              iVar4 = types_compatible(pcVar6->type,uVar8);
              if (iVar4 == 0) {
                pcVar6 = symbol_get_part(pcVar6,uVar8,uVar8 & 0xfff,0);
                pcVar1->sym = pcVar6;
              }
            }
          }
        }
        if ((((t->op == 0x19e) && ((t->type & 0xf000) == 0x4000)) &&
            ((1 << (t->src->kind & 0x1f) & 6U) != 0)) &&
           ((pcVar5 = t->src->sym->def, pcVar5 != (c2_tuple *)0x0 && (pcVar5->op == 0x15b)))) {
          pcVar1 = pcVar5->src;
          size = pcVar1->type & 0xfff;
          uVar8 = (ushort)size | 0x2000;
          if (pcVar1->kind == '\x02') {
            pcVar6 = symbol_get_part(pcVar1->sym,uVar8,size,0);
            pcVar1->sym = pcVar6;
          }
          pcVar1->type = uVar8;
          pcVar7 = tuple_new_unary_temp(0x15b,uVar8,pcVar1,tuple_insert_before,t);
          tuple_replace_src(t,t->src,pcVar7->dst);
          t->type = uVar8;
          tuple_delete(pcVar5);
        }
        bVar2 = false;
        if (((t->kind == '\x10') && (pcVar1 = t->dst, pcVar1 != (c2_operand *)0x0)) &&
           (((1 << (pcVar1->kind & 0x1f) & 6U) == 0 || (pcVar1->sym->def == (c2_tuple *)0x0)))) {
          bVar2 = true;
        }
        if ((((((t->kind == '\x12') && (pcVar1 = t->dst, pcVar1 != (c2_operand *)0x0)) &&
              ((1 << (pcVar1->kind & 0x1f) & 6U) != 0)) && (pcVar1->sym->def == (c2_tuple *)0x0)) &&
            (((iVar4 = node_has_side_effects((c2_node *)t), iVar4 != 0 ||
              (uVar3 = (t->u20).intrinsic.id, uVar3 == 0xa2)) ||
             ((uVar3 == 0xa1 || ((uVar3 == 0xa0 || (uVar3 == 0x9f)))))))) || (bVar2)) {
          pcVar1 = t->dst;
          src = operand_new_temp(pcVar1->type);
          pcVar5 = tuple_new(0x15b,pcVar1->type,pcVar1,src,tuple_insert_after,t);
          tuple_replace_dst(t,pcVar1,src);
          src->sym->def = t;
          local_c = pcVar5;
        }
        if (t->kind == '\x12') {
          uVar3 = (t->u20).intrinsic.id;
          if (uVar3 == 0xac) {
            uVar3 = tuple_take_block_op_type(t,&local_10);
            if (local_10 == 0) {
              (t->u20).intrinsic.id = 0x96;
              goto LAB_1071e5d3;
            }
          }
          else if ((uVar3 == 0xad) && (uVar3 = tuple_take_block_op_type(t,&local_10), local_10 == 0)
                  ) {
            (t->u20).intrinsic.id = 0x97;
LAB_1071e5d3:
            lower_float_compare_to_int(t,uVar3);
          }
        }
      }
      t = local_c;
    } while (local_c != local_4);
  }
  return;
}

