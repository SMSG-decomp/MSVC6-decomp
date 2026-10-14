c2_node * __fastcall
narrow_operator_operands(c2_tuple *t,c2_node *convert,uint16_t narrow_type,c2_tuple *user)

{
  c2_operand *pcVar1;
  c2_symbol *pcVar2;
  c2_tuple *pcVar3;
  int iVar4;
  c2_operand *child;
  c2_symbol *sym;
  uint32_t uVar5;
  uint64_t uVar6;
  undefined2 in_stack_00000006;
  
  child = t->src;
  do {
    if (child == (c2_operand *)0x0) {
      return (c2_node *)0x0;
    }
    if (child != (c2_operand *)convert) {
      if (child->kind != '\a') {
        if ((child->op != 0x15f) ||
           (iVar4 = conversion_changes_value(narrow_type,((child->u18).children)->type), iVar4 != 0)
           ) goto LAB_1070c905;
        if (child->kind != '\a') {
          if ((child->op != 0x15f) ||
             (iVar4 = conversion_changes_value(narrow_type,((child->u18).children)->type),
             iVar4 != 0)) {
            ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\optimize.c",0x4b8);
          }
          if (((child->u18).children)->type == narrow_type) {
            child = tuple_forward_src_and_free((c2_tuple *)child,t);
          }
          else {
            pcVar1 = (c2_operand *)child->tag;
            child->type = narrow_type;
            symbol_free_chain(pcVar1->sym);
            sym = symbol_new_temp(narrow_type);
            pcVar2 = sym->storage;
            pcVar1->sym = sym;
            pcVar1->type = narrow_type;
            if (pcVar2->part_next == (c2_symbol *)0x0) {
              sym->def = (c2_tuple *)child;
            }
            else {
              symbol_mark_overlapping_parts(sym,(c2_tuple *)child);
            }
            child = (c2_operand *)simplify_conversion_chain((c2_tuple *)child,t);
          }
          goto LAB_1070c957;
        }
      }
      uVar5 = _narrow_type;
      if ((t->op == 0x172) && ((t->type & 0xf000) == 0x1000)) {
        pcVar1 = (c2_operand *)(child->u18).lo;
        uVar6 = const_normalize(narrow_type,(uint32_t)pcVar1,(int32_t)child->tag);
        if (((c2_operand *)uVar6 != pcVar1) ||
           ((c2_operand *)(uVar6 >> 0x20) != (c2_operand *)child->tag)) {
          uVar5 = narrow_type & 0xfff | 0x2000;
        }
      }
      pcVar1 = (c2_operand *)(child->u18).lo;
      uVar6 = const_normalize((uint16_t)uVar5,(uint32_t)pcVar1,(int32_t)child->tag);
      if (((c2_operand *)uVar6 == pcVar1) &&
         ((c2_operand *)(uVar6 >> 0x20) == (c2_operand *)child->tag)) {
        child->type = (uint16_t)uVar5;
        _narrow_type = uVar5;
LAB_1070c957:
        if (t->src->next->next == (c2_operand *)0x0) {
          pcVar3 = narrow_operator_through_conversion(t,(c2_tuple *)convert,_narrow_type,user);
          return (c2_node *)pcVar3;
        }
        tuple_detach_src((c2_node *)t,child);
        tuple_detach_src((c2_node *)t,(c2_operand *)convert);
        child = (c2_operand *)
                tuple_new_binary_temp
                          (t->op,t->type,child,(c2_operand *)convert,(c2_insert_fn *)0x0,
                           (c2_tuple *)0x0);
        tuple_unlink_mem_subops((c2_tuple *)child);
        *(undefined1 *)&child->x12 = 2;
        tuple_append_src(t,child);
        narrow_operator_through_conversion((c2_tuple *)child,(c2_tuple *)convert,_narrow_type,t);
        return (c2_node *)t;
      }
    }
LAB_1070c905:
    child = child->next;
  } while( true );
}

