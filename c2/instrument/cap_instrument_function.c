void __fastcall cap_instrument_function(c2_function *fn)

{
  byte bVar1;
  ushort uVar2;
  c2_fe_symbol *sym;
  c2_tuple *anchor;
  c2_operand *pcVar3;
  c2_operand *pcVar4;
  c2_tuple *pcVar5;
  c2_tuple *pcVar6;
  c2_tuple *local_8;
  
  if (((fn->flags & 0x800) == 0) && (sym = fn->fsym, (sym->attrs & 0x400) == 0)) {
    pcVar6 = (c2_tuple *)0x0;
    local_8 = (c2_tuple *)0x0;
    for (anchor = fn->cfg->first->head; anchor != (c2_tuple *)0x0; anchor = anchor->next) {
      bVar1 = anchor->kind;
      if (((((1 << (bVar1 & 0x1f) & 0xa0000U) == 0) && (bVar1 != 0x1a)) && (bVar1 != 0x15)) &&
         (bVar1 != 0x18)) {
        if ((anchor->flags & 1) != 0) {
          if (pcVar6 == (c2_tuple *)0x0) {
            pcVar6 = anchor->prev;
            local_8 = pcVar6;
          }
          if ((g_opt_fastcap != 0) && (bVar1 == 0xe)) {
            pcVar3 = anchor->src;
            if (((1 << (pcVar3->kind & 0x1f) & 6U) == 0) ||
               (pcVar6 = pcVar3->sym->def, pcVar6 == (c2_tuple *)0x0)) {
              if (((pcVar3->kind == 6) &&
                  ((pcVar4 = pcVar3->base, pcVar4 == (c2_operand *)0x0 ||
                   (((1 << (pcVar4->kind & 0x1f) & 6U) != 0 && (pcVar4->sym->def != (c2_tuple *)0x0)
                    ))))) &&
                 ((pcVar3 = pcVar3->index, pcVar3 == (c2_operand *)0x0 ||
                  (((1 << (pcVar3->kind & 0x1f) & 6U) != 0 && (pcVar3->sym->def != (c2_tuple *)0x0))
                  )))) {
                pcVar6 = pcVar4->sym->def;
                goto LAB_107963bc;
              }
            }
            else {
LAB_107963bc:
              instrument_split_result_through_temp(pcVar6);
            }
            pcVar3 = operand_new_codeaddr(0x153,sym);
            pcVar4 = (c2_operand *)node_clone((c2_node *)anchor->src);
            pcVar6 = tuple_new_unary_temp(0x15a,0x2004,pcVar4,tuple_insert_before,anchor);
            pcVar5 = tuple_new_unary_temp(0x15a,0x2004,pcVar3,tuple_insert_before,anchor);
            tuple_new_intrinsic(400,0x2004,(c2_operand *)0x0,pcVar5->dst,pcVar6->dst,
                                (c2_operand *)0x0,(c2_operand *)0x0,0x188,tuple_insert_before,anchor
                               );
            pcVar3 = operand_new_codeaddr(0x153,sym);
            pcVar6 = anchor->next;
            pcVar5 = tuple_new_unary_temp(0x15a,0x2004,pcVar3,tuple_insert_before,pcVar6);
            tuple_new_intrinsic(400,0x2004,(c2_operand *)0x0,pcVar5->dst,(c2_operand *)0x0,
                                (c2_operand *)0x0,(c2_operand *)0x0,0x189,tuple_insert_before,pcVar6
                               );
            pcVar6 = local_8;
          }
        }
      }
      else if (pcVar6 != (c2_tuple *)0x0) {
        if (g_opt_cap != 0) {
          uVar2 = pcVar6->next->line;
          if (uVar2 != 0) {
            g_current_line_abs = fn->line_base + (uint)uVar2;
            g_cur_line = uVar2;
          }
          pcVar3 = operand_new_codeaddr(0x153,sym);
          pcVar6 = tuple_new_unary_temp(0x15a,0x2004,pcVar3,tuple_insert_after,pcVar6);
          tuple_new_intrinsic(400,0x2004,(c2_operand *)0x0,pcVar6->dst,(c2_operand *)0x0,
                              (c2_operand *)0x0,(c2_operand *)0x0,0x187,tuple_insert_after,pcVar6);
        }
        local_8 = (c2_tuple *)0x0;
        pcVar6 = (c2_tuple *)0x0;
      }
    }
  }
  return;
}

