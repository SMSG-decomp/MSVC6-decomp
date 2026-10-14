int __fastcall switch_prune_and_merge_cases(c2_switch_case_range *cases)

{
  c2_tuple *t;
  c2_operand *pcVar1;
  c2_symbol *pcVar2;
  c2_tuple *pcVar3;
  c2_tuple *pcVar4;
  int iVar5;
  c2_switch_case_range *pcVar6;
  c2_tuple *pcVar7;
  int local_10;
  c2_switch_case_range *local_c;
  c2_symbol *local_8;
  
  t = cases->label;
  if (cases == (c2_switch_case_range *)0x0) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\switch.c",600);
  }
  pcVar3 = tuple_next_real(t);
  if ((((pcVar3 == (c2_tuple *)0x0) || (pcVar3->kind != '\x11')) ||
      ((pcVar3->u20).cond_cells != (c2_cond_cell *)0x0)) || (pcVar3->op == 0x18b)) {
    local_8 = (c2_symbol *)0x0;
    local_10 = -1;
    local_c = cases;
  }
  else {
    local_10 = -1;
    local_8 = pcVar3->src->sym;
    local_c = cases;
  }
  do {
    pcVar6 = local_c->next;
    iVar5 = local_10 + 1;
    if (pcVar6 != (c2_switch_case_range *)0x0) {
      pcVar3 = tuple_next_real(pcVar6->label);
      if (((g_opt_global != 0) && (pcVar3 != (c2_tuple *)0x0)) && (pcVar3->op == 0x1ab)) {
        for (pcVar7 = (pcVar3->u20).default_label; pcVar7 != (c2_tuple *)0x0; pcVar7 = pcVar7->next)
        {
          if (((pcVar7->op == 0x1ac) && (pcVar1 = pcVar7->src, pcVar1->kind == '\a')) &&
             ((pcVar1->u18).reg == (c2_symbol *)0x0 && pcVar1->tag == 0)) goto LAB_1074e2a3;
        }
        do {
          pcVar3 = tuple_next_real(pcVar3);
          if (pcVar3 == (c2_tuple *)0x0) goto LAB_1074e2f9;
        } while ((pcVar3->op == 0x1ab) && (pcVar3->next != (c2_tuple *)0x0));
        if ((pcVar3 != (c2_tuple *)0x0) &&
           (((pcVar3->kind == '\x11' && ((pcVar3->u20).cond_cells == (c2_cond_cell *)0x0)) &&
            (pcVar7 = pcVar3, pcVar3->op != 0x18b)))) {
          do {
            if (pcVar7->op != 0x1ab) break;
            pcVar4 = tuple_next_real(pcVar7);
            tuple_unlink_free(pcVar7);
            pcVar7 = pcVar4;
          } while (pcVar4 != (c2_tuple *)0x0);
        }
      }
LAB_1074e2f9:
      if ((pcVar6->label == t) ||
         ((((pcVar3 != (c2_tuple *)0x0 && (pcVar3->kind == '\x11')) &&
           (((pcVar3->u20).cond_cells == (c2_cond_cell *)0x0 && (pcVar3->op != 0x18b)))) &&
          ((pcVar2 = pcVar3->src->sym, pcVar2 == (c2_symbol *)t->src ||
           ((local_8 != (c2_symbol *)0x0 && (pcVar2 == local_8)))))))) {
        local_c->next = pcVar6->next;
        pcVar6 = local_c;
        iVar5 = local_10;
      }
      else if (((local_c->label == pcVar6->label) && (local_c->last == pcVar6->first - 1)) &&
              (local_c->last_high == pcVar6->first_high - (uint)(pcVar6->first == 0))) {
        local_c->last = pcVar6->last;
        local_c->last_high = pcVar6->last_high;
LAB_1074e2a3:
        local_c->next = pcVar6->next;
        pcVar6 = local_c;
        iVar5 = local_10;
      }
    }
    local_10 = iVar5;
    local_c = pcVar6;
    if (pcVar6 == (c2_switch_case_range *)0x0) {
      return local_10;
    }
  } while( true );
}

