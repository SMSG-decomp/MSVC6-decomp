int __fastcall cse_replace_operands(c2_tuple *t)

{
  uint8_t *puVar1;
  c2_list_cell_u04 *pcVar2;
  byte bVar3;
  ushort uVar4;
  c2_function *pcVar5;
  c2_loop *pcVar6;
  c2_list_cell *pcVar7;
  c2_list_cell *pcVar8;
  c2_operand *pcVar9;
  c2_operand *pcVar10;
  c2_operand *old;
  uint32_t size;
  c2_symbol *pcVar11;
  c2_tuple *pcVar12;
  int iVar13;
  c2_operand *local_c;
  c2_operand *local_8;
  c2_operand *local_4;
  
  iVar13 = 0;
  local_c = t->src;
  if (local_c != (c2_operand *)0x0) {
    do {
      pcVar10 = local_c->next;
      pcVar9 = find_available_copy_source(t,local_c);
      if (pcVar9 != (c2_operand *)0x0) {
        if (((local_c->flags & 0x20) == 0) || (pcVar9->kind != '\x03')) {
          if (((1 << (local_c->kind & 0x1f) & 6U) == 0) ||
             (((pcVar11 = local_c->sym, pcVar11->cls != '\x03' || (pcVar11->def != (c2_tuple *)0x0))
              || (local_8 = (c2_operand *)0x1, (pcVar11->storage->flags7 & 2) == 0)))) {
            local_8 = (c2_operand *)0x0;
          }
          uVar4 = local_c->type;
          if (pcVar9->kind == '\a') {
            pcVar9 = constant_convert((uint)uVar4,pcVar9);
          }
          pcVar10 = tuple_replace_src(t,local_c,pcVar9);
          pcVar10->type = uVar4;
          if ((((1 << (pcVar10->kind & 0x1f) & 6U) != 0) &&
              (pcVar11 = pcVar10->sym, pcVar11->cls == '\x03')) &&
             ((pcVar11->def == (c2_tuple *)0x0 && (local_8 != (c2_operand *)0x0)))) {
            puVar1 = &pcVar11->storage->flags7;
            *puVar1 = *puVar1 | 2;
          }
          if ((pcVar10->flags & 0x20) == 0) {
            local_c = pcVar10->next;
          }
          else {
            cse_number_memory_bases(t);
            local_c = t->src;
          }
        }
        else {
          old = find_mem_operand_using(t,local_c,&local_4);
          bVar3 = old->flags;
          local_8 = (c2_operand *)CONCAT22(local_8._2_2_,old->type);
          if (old->kind == '\x06') {
            operand_to_memory_form(pcVar9);
            pcVar11 = pcVar9->sym->storage;
            iVar13 = pcVar9->sym->offset - pcVar11->offset;
            size = (uint)local_8 & 0xfff;
            if (size == 0) {
              size = pcVar11->size - iVar13;
            }
            pcVar11 = symbol_get_part(pcVar11,(uint16_t)local_8,size,iVar13);
            pcVar9->sym = pcVar11;
          }
          pcVar9->type = (uint16_t)local_8;
          pcVar9->flags = (char)((bVar3 & 0x40) >> 6) << 6 | pcVar9->flags & 0xbf;
          if (local_4 == t->src) {
            tuple_replace_src(t,old,pcVar9);
            local_c = t->src;
          }
          else {
            tuple_replace_dst(t,old,pcVar9);
            local_c = pcVar10;
          }
        }
        iVar13 = 1;
        pcVar10 = local_c;
        if (((t->op == 0x15d) && (pcVar9 = t->src, pcVar9->kind != '\x06')) &&
           (t->op = 0x15b, (1 << (pcVar9->kind & 0x1f) & 6U) != 0)) {
          pcVar11 = t->dst->sym;
          if (((pcVar11 != pcVar9->sym) &&
              (pcVar5 = (pcVar11->u18).inline_callee, pcVar5 != (c2_function *)0x0)) &&
             (pcVar6 = pcVar5->loops, *(char *)&pcVar6->parent == '\x06')) {
            cse_add_copy_link(pcVar9->sym,(c2_symbol *)pcVar6->last);
          }
        }
      }
      local_c = pcVar10;
    } while (local_c != (c2_operand *)0x0);
    if (((((iVar13 != 0) && (t->op == 0x15a)) &&
         ((pcVar12 = find_next_use_of_dst(t,&local_8), pcVar7 = g_pending_tuples,
          pcVar12->kind == '\x12' &&
          ((g_intrinsic_desc[(pcVar12->u20).intrinsic.id].flags & 0x20) != 0)))) &&
        ((g_opt_basic == 0 || ((pcVar12->type & 0xf000) != 0x4000)))) &&
       ((g_pending_tuples == (c2_list_cell *)0x0 || ((g_pending_tuples->u04).tuple != pcVar12)))) {
      if (g_list_node_free == (c2_list_cell *)0x0) {
        refill_list_node_pool();
      }
      pcVar8 = g_list_node_free;
      g_pending_tuples = g_list_node_free;
      pcVar2 = &g_list_node_free->u04;
      g_list_node_free = g_list_node_free->next;
      pcVar2->tuple = pcVar12;
      pcVar8->next = pcVar7;
    }
  }
  return iVar13;
}

