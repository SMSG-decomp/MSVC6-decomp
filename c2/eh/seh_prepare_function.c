void __fastcall seh_prepare_function(c2_function *fn)

{
  c2_operand *pcVar1;
  c2_tuple *pcVar2;
  c2_symbol *pcVar3;
  uint32_t uVar4;
  c2_tuple *t;
  c2_fe_symbol *label_sym;
  c2_tuple *pcVar5;
  int iVar6;
  
  fn->flags = fn->flags | 0x2000;
  pcVar5 = fn->cfg->first->head;
  pcVar2 = pcVar5;
joined_r0x10795630:
  if (pcVar2 != (c2_tuple *)0x0) {
    if (((((pcVar2->flags & 1) == 0) || (pcVar1 = pcVar2->dst, pcVar1 == (c2_operand *)0x0)) ||
        (pcVar1->kind != '\x02')) ||
       ((pcVar1->sym->cls != '\x04' || ((pcVar1->sym->storage->fe->attrs & 0x100000) == 0))))
    goto LAB_1079565e;
    if (pcVar2 != (c2_tuple *)0x0) {
      pcVar3 = pcVar2->dst->sym->storage;
      g_seh_param_storage = pcVar3;
      for (pcVar2 = pcVar5; pcVar2 != (c2_tuple *)0x0; pcVar2 = pcVar2->next) {
        if ((pcVar2->flags & 1) != 0) {
          iVar6 = 0;
          do {
            if (iVar6 == 0) {
              pcVar1 = pcVar2->dst;
            }
            else {
              pcVar1 = pcVar2->src;
            }
            for (; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
              if ((pcVar1->kind == '\x02') && (pcVar1->sym->storage == pcVar3)) {
                pcVar1->flags = pcVar1->flags | 0x40;
              }
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 < 2);
        }
      }
      goto LAB_1079566e;
    }
  }
  g_seh_param_storage = (c2_symbol *)0x0;
LAB_1079566e:
  if (g_opt_global == 0) {
    if (pcVar5 != (c2_tuple *)0x0) {
      while (pcVar5->op != 0x194) {
        pcVar5 = pcVar5->next;
        if (pcVar5 == (c2_tuple *)0x0) {
          g_seh_try_end_label = pcVar5;
          return;
        }
      }
LAB_10795731:
      if (pcVar5 != (c2_tuple *)0x0) {
        pcVar2 = pcVar5->next;
        g_seh_try_has_code = 0;
        uVar4 = pcVar2->op;
        while (uVar4 != 0x194) {
          if ((pcVar2->flags & 1) != 0) {
            g_seh_try_has_code = 1;
          }
          pcVar2 = pcVar2->next;
          uVar4 = pcVar2->op;
        }
        label_sym = label_symbol_new();
        pcVar5 = tuple_new_label(label_sym);
        g_seh_try_end_label = pcVar5;
        *(uint *)((int)&pcVar5->src[1].rank + 2) = *(uint *)((int)&pcVar5->src[1].rank + 2) | 1;
        tuple_insert_after(pcVar2,pcVar5);
        tuple_unlink_free(pcVar2);
        return;
      }
    }
  }
  else {
    for (; pcVar5 != (c2_tuple *)0x0; pcVar5 = pcVar5->next) {
      if (pcVar5->op == 0x18b) {
        pcVar2 = *(c2_tuple **)((int)&pcVar5->src->sym->u30 + 2);
        if (pcVar2->next->op != 0x19c) {
          t = tuple_new_pseudo(0x19c,0x1004);
          tuple_insert_after(pcVar2,t);
        }
      }
      else if (pcVar5->op == 0x194) goto LAB_10795731;
    }
  }
  g_seh_try_end_label = (c2_tuple *)0x0;
  return;
LAB_1079565e:
  pcVar2 = pcVar2->next;
  goto joined_r0x10795630;
}

