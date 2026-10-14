void __fastcall narrow_logical_immediates(c2_function *fn)

{
  ushort uVar1;
  c2_tuple *pcVar2;
  uint32_t uVar3;
  c2_operand *pcVar4;
  c2_operand *pcVar5;
  int iVar6;
  c2_tuple *t;
  uint32_t local_18;
  c2_operand *local_14;
  uint32_t local_10;
  c2_function *local_c;
  c2_operand *local_8;
  c2_cfg *local_4;
  
  local_4 = fn->cfg;
  local_18 = 0;
  local_10 = 0;
  t = local_4->last->end->prev;
  local_c = fn;
  if (t != local_4->first->head) {
    do {
      pcVar2 = t->prev;
      if ((t->flags & 1) != 0) {
        uVar1 = t->line;
        if (uVar1 != 0) {
          g_current_line_abs = local_c->line_base + (uint)uVar1;
          g_cur_line = uVar1;
        }
        uVar3 = t->op;
        if ((((uVar3 == 0x2e) || (uVar3 == 0x30)) || (uVar3 == 0x33)) &&
           (t->src->next->kind == '\a')) {
          pcVar4 = t->dst;
          if (pcVar4->kind == '\x01') {
            if (pcVar4->sym->cls == '\x03') {
              pcVar5 = (c2_operand *)pcVar4->sym->def;
              if (pcVar5 == (c2_operand *)0x0) {
                local_14 = pcVar5;
                find_next_use_of_symbol((c2_node *)t,pcVar4->sym,&local_14);
                if (local_14 == (c2_operand *)0x0) goto LAB_1077d15a;
                uVar1 = local_14->type;
              }
              else {
                find_next_use_of_dst(t,&local_8);
                uVar1 = local_8->type;
              }
              local_18 = uVar1 & 0xfff;
              if (-1 < (int)local_18) goto LAB_1077d0c9;
            }
            else {
LAB_1077d15a:
              local_18 = 0xffffffff;
            }
          }
          else {
            local_18 = 0;
LAB_1077d0c9:
            iVar6 = narrow_immediate_operation(t,&local_18,&local_10);
            if (iVar6 != 0) {
              narrow_and_or_constant(t,local_18,local_10);
            }
          }
        }
      }
      t = pcVar2;
    } while (pcVar2 != local_4->first->head);
  }
  return;
}

