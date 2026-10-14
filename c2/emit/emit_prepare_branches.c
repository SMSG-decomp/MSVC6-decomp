void __fastcall emit_prepare_branches(c2_function *fn)

{
  uint *puVar1;
  c2_tuple *pcVar2;
  c2_tuple *t;
  c2_tuple *pcVar3;
  int iVar4;
  c2_fe_symbol *label_sym;
  int iVar5;
  
  iVar5 = 0;
  pcVar2 = fn->cfg->last->end;
  pcVar3 = fn->cfg->first->head->next;
  if (pcVar3 != pcVar2) {
    do {
      t = pcVar3->next;
      if (pcVar3->op == 0x18c) {
        iVar5 = *(int *)((int)&pcVar3->src->sym->u30 + 2);
        tuple_unlink_free(pcVar3);
        if (((g_opt_debug_info != 0) && (pcVar3 = tuple_prev_real(t), pcVar3 != (c2_tuple *)0x0)) &&
           (iVar4 = tuple_label_may_follow(pcVar3), iVar4 != 0)) {
          label_sym = label_symbol_new();
          pcVar3 = tuple_new_label(label_sym);
          tuple_insert_before(t,pcVar3);
          *(uint *)((int)&pcVar3->src[1].rank + 2) = *(uint *)((int)&pcVar3->src[1].rank + 2) | 3;
        }
      }
      else if ((pcVar3->kind == '\x11') &&
              (((pcVar3->u20).cond_cells != (c2_cond_cell *)0x0 || (pcVar3->op == 0x18b)))) {
        *(char *)&pcVar3->type = (char)g_cond_to_x86_cc[(byte)pcVar3->type];
      }
      pcVar3 = t;
    } while (t != pcVar2);
    if (iVar5 != 0) {
      puVar1 = (uint *)(*(int *)(iVar5 + 0x18) + 0x3e);
      *puVar1 = *puVar1 | 3;
    }
  }
  return;
}

