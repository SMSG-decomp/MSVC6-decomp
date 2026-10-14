void __fastcall seh_mark_try_region_memory_ops(c2_function *fn)

{
  c2_tuple *anchor;
  c2_tuple *t;
  c2_seh_try_scope *pcVar1;
  c2_operand *pcVar2;
  c2_operand *pcVar3;
  int iVar4;
  c2_symbol *pcVar5;
  int iVar6;
  int local_4;
  
  iVar6 = 0;
  local_4 = 0;
  anchor = fn->cfg->first->head;
  do {
    if (anchor == (c2_tuple *)0x0) {
      arena_reset(4);
      return;
    }
    switch(anchor->op) {
    case 0x192:
      pcVar1 = (anchor->u20).seh_scope;
      iVar6 = iVar6 + 1;
      seh_scope_stack_push(pcVar1);
      tuple_new_branch(0x18b,'\0',(c2_node *)(pcVar1->handler_label->u32).label_tuple,
                       (c2_operand *)0x0,(c2_tuple *)0x0,tuple_insert_after,anchor);
      if (pcVar1->kind == 1) {
        t = (pcVar1->filter_label->u32).label_tuple;
        seh_note_try_body_symbols(t);
        tuple_new_branch(0x18b,'\0',(c2_node *)t,(c2_operand *)0x0,(c2_tuple *)0x0,
                         tuple_insert_after,anchor);
      }
      break;
    case 0x193:
      pcVar1 = (anchor->u20).seh_scope;
      iVar6 = iVar6 + -1;
      seh_scope_stack_pop();
      tuple_new_branch(0x18b,'\0',(c2_node *)(pcVar1->handler_label->u32).label_tuple,
                       (c2_operand *)0x0,(c2_tuple *)0x0,tuple_insert_before,anchor);
      if (pcVar1->kind == 1) {
        tuple_new_branch(0x18b,'\0',(c2_node *)(pcVar1->filter_label->u32).label_tuple,
                         (c2_operand *)0x0,(c2_tuple *)0x0,tuple_insert_after,anchor);
      }
      break;
    default:
      if (((anchor->flags & 1) != 0) && ((iVar6 != 0 || (local_4 != 0)))) {
        pcVar2 = anchor->dst;
        for (pcVar3 = pcVar2; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
          if (((1 << (pcVar3->kind & 0x1f) & 6U) == 0) || (pcVar3->sym->cls != '\x03')) {
            pcVar3->flags11 = pcVar3->flags11 | 8;
          }
        }
        if (iVar6 != 0) {
          for (; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
            if (pcVar2->kind == '\x02') {
              pcVar5 = pcVar2->sym;
LAB_1075b9a7:
              if (((pcVar5 != (c2_symbol *)0x0) && (pcVar5->cls != '\x03')) &&
                 (iVar4 = seh_try_region_holds_symbol(pcVar5), iVar4 != 0)) {
                pcVar2->flags = pcVar2->flags | 0x40;
              }
            }
            else if (pcVar2->kind == '\x06') {
              pcVar5 = pcVar2->base_sym;
              goto LAB_1075b9a7;
            }
          }
          for (pcVar2 = anchor->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
            if (pcVar2->kind == '\x02') {
              pcVar5 = pcVar2->sym;
LAB_1075ba6f:
              if (((pcVar5 != (c2_symbol *)0x0) && (pcVar5->cls != '\x03')) &&
                 (iVar4 = seh_try_region_holds_symbol(pcVar5), iVar4 != 0)) {
                pcVar2->flags = pcVar2->flags | 0x40;
              }
            }
            else if (pcVar2->kind == '\x06') {
              pcVar5 = pcVar2->base_sym;
              goto LAB_1075ba6f;
            }
          }
        }
      }
      break;
    case 0x198:
      local_4 = local_4 + 1;
      break;
    case 0x19a:
      local_4 = local_4 + -1;
    }
    anchor = anchor->next;
  } while( true );
}

