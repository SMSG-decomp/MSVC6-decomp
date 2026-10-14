c2_tuple * __fastcall
inline_bind_formal_parameters
          (c2_tuple *call,c2_inline_binding *bindings,c2_tuple *first,c2_tuple *last)

{
  byte bVar1;
  uint16_t uVar2;
  c2_symbol *pcVar3;
  c2_operand *pcVar4;
  int a;
  uint32_t uVar5;
  c2_symbol *pcVar6;
  c2_fe_symbol *pcVar7;
  c2_list_cell *cell;
  c2_operand *new_op;
  c2_tuple *pcVar8;
  c2_tuple *t;
  c2_inline_binding *binding;
  c2_list_cell *new_locals;
  
  new_locals = (c2_list_cell *)0x0;
  binding = bindings;
  if (bindings != (c2_inline_binding *)0x0) {
    do {
      pcVar3 = binding->formal;
      pcVar4 = binding->value;
      pcVar6 = pcVar3->storage;
      (pcVar6->u18).expr = (c2_cse_expr *)0x0;
      if (pcVar4 == (c2_operand *)0x0) {
        pcVar8 = binding->arg;
        pcVar6 = symbol_get_part(pcVar3,pcVar8->type,pcVar8->type & 0xfff,0);
        pcVar3 = pcVar6->storage;
        a = pcVar6->size;
        pcVar7 = pcVar3->fe;
        binding->formal = pcVar3;
        pcVar7 = fe_symbol_new_local_cur((byte)pcVar7->storage & 0xf,a,1,1,'\x04',0);
        if (g_opt_global != 0) {
          cell = arena_alloc(1,8);
          (cell->u04).fe = pcVar7;
          cell->next = new_locals;
          new_locals = cell;
        }
        pcVar7->storage_sym = pcVar3;
        pcVar3->fe = pcVar7;
        for (; pcVar3 != (c2_symbol *)0x0; pcVar3 = pcVar3->part_next) {
          pcVar3->cls = '\x04';
        }
        if (call->flags12 != '\0') {
          tuple_unlink(pcVar8);
          tuple_insert_after(first,pcVar8);
          hoist_defining_tuples(pcVar8,'\0');
          first = pcVar8;
        }
        pcVar8->op = (-(uint)(pcVar8->op != 0x15a) & 0x10) + 0x15b;
        pcVar4 = pcVar8->dst;
        symbol_free_chain(pcVar4->sym);
        new_op = operand_new_sym(0x14a,pcVar8->type,pcVar6);
        tuple_replace_dst(pcVar8,pcVar4,new_op);
      }
      else {
        bVar1 = pcVar4->kind;
        if (pcVar4->rank == 0) {
          if (((1 << (bVar1 & 0x1f) & 6U) == 0) ||
             (pcVar8 = pcVar4->sym->def, pcVar8 == (c2_tuple *)0x0)) {
            if ((bVar1 == 6) &&
               (((1 << (pcVar4->base->kind & 0x1f) & 6U) != 0 &&
                (pcVar8 = pcVar4->base->sym->def, pcVar8 != (c2_tuple *)0x0)))) {
              tuple_delete_if_dead((c2_node *)pcVar8,0);
            }
          }
          else {
            tuple_delete_if_dead((c2_node *)pcVar8,0);
          }
        }
        else if (((bVar1 == 2) && (pcVar3 = pcVar4->sym, pcVar3->cls == '\x03')) &&
                (pcVar3->def == (c2_tuple *)0x0)) {
          retype_symbol_chain_to_local(pcVar3);
        }
        pcVar8 = binding->arg;
        if (first == pcVar8) {
          first = first->prev;
        }
        symbol_free_chain(pcVar8->dst->sym);
        tuple_unlink_free(pcVar8);
        symbol_free_chain(pcVar6);
        if ((pcVar4->flags & 0x10) == 0) {
          node_free((c2_node *)pcVar4);
        }
      }
      binding = binding->next;
    } while (binding != (c2_inline_binding *)0x0);
    if (new_locals != (c2_list_cell *)0x0) {
      pcVar8 = tuple_new_marker(0x1b4);
      (pcVar8->u14).scope_locals = new_locals;
      pcVar8->flags12 = '\x01';
      uVar2 = call->line;
      pcVar8->line = uVar2;
      tuple_insert_after(first,pcVar8);
      t = tuple_new_marker(0x1b5);
      t->line = uVar2;
      (t->u14).scope_locals = new_locals;
      uVar5 = last->op;
      t->flags12 = '\x01';
      while (uVar5 != 0x1b1) {
        last = last->prev;
        uVar5 = last->op;
      }
      tuple_insert_before(last,t);
      return pcVar8;
    }
  }
  return first;
}

