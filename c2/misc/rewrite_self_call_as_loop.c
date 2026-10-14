int __fastcall rewrite_self_call_as_loop(c2_function *fn,c2_block *from,c2_tuple *call)

{
  uint16_t type;
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  c2_block *to;
  c2_symbol_cell **ppcVar3;
  c2_symbol_cell *pcVar4;
  c2_symbol_cell *member_cell;
  c2_operand *pcVar5;
  c2_symbol *member;
  c2_tuple *pcVar6;
  c2_tuple *t2;
  uint32_t uVar7;
  c2_const_operand *size;
  c2_symbol *pcVar8;
  c2_symbol_cell *pcVar9;
  c2_operand *dst;
  c2_operand *local_10;
  
  for (pcVar6 = fn->cfg->first->head; (pcVar6 != (c2_tuple *)0x0 && (pcVar6->kind != '\x17'));
      pcVar6 = pcVar6->next) {
  }
  dst = pcVar6->src;
  pcVar1 = call->src->next;
  pcVar5 = dst;
  for (pcVar2 = pcVar1; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
    if (pcVar5 == (c2_operand *)0x0) goto LAB_1075a109;
    if (pcVar2->kind == '\v') break;
    if ((pcVar2->flags & 0x20) == 0) {
      pcVar5 = pcVar5->next;
    }
  }
  if (pcVar5 != (c2_operand *)0x0) {
    return 0;
  }
LAB_1075a109:
  if (pcVar2 != (c2_operand *)0x0) {
    if (pcVar2->kind != '\v') {
      return 0;
    }
    pcVar4 = alias_class_members((uint32_t)pcVar2->sym);
    pcVar9 = (c2_symbol_cell *)0x0;
joined_r0x1075a123:
    if (pcVar4 != (c2_symbol_cell *)0x0) {
      do {
        pcVar8 = pcVar4->sym;
        member_cell = pcVar4;
        if (pcVar8->cls == '\f') {
          member_cell = (pcVar8->u30).members;
          pcVar9 = pcVar4;
          if (member_cell == (c2_symbol_cell *)0x0) {
            pcVar4 = pcVar4->next;
            goto joined_r0x1075a123;
          }
          pcVar8 = member_cell->sym;
        }
        if (pcVar8->cls == '\x04') {
          return 0;
        }
        if (pcVar8->cls == '\x05') {
          return 0;
        }
        pcVar4 = member_cell->next;
      } while (pcVar4 != (c2_symbol_cell *)0x0);
      if (pcVar9 == (c2_symbol_cell *)0x0) goto LAB_1075a156;
      ppcVar3 = &pcVar9->next;
      pcVar9 = (c2_symbol_cell *)0x0;
      pcVar4 = *ppcVar3;
      goto joined_r0x1075a123;
    }
  }
LAB_1075a156:
  local_10 = dst;
  if (call->line != 0) {
    g_current_line_abs = fn->line_base + (uint)call->line;
    g_cur_line = call->line;
  }
  for (; (pcVar1 != (c2_operand *)0x0 && (pcVar1->kind != '\v')); pcVar1 = pcVar1->next) {
    if ((pcVar1->flags & 0x20) == 0) {
      type = dst->type;
      pcVar6 = pcVar1->sym->def;
      pcVar5 = operand_new_temp_sym(type);
      pcVar5->sym->flags7 = pcVar5->sym->flags7 | 2;
      if ((type & 0xf000) == 0x5000) {
        retype_symbol_chain_to_local(pcVar5->sym);
        uVar7 = alias_assign_reserved_class(pcVar5->sym);
        (pcVar5->sym->fe->u3e).alias_class = (uint16_t)uVar7;
        size = operand_new_intconst(0x1004,dst->type & 0xfff,0);
        size->flags = size->flags | 0x10;
        tuple_new_blockop(0x16b,type,pcVar5,pcVar6->src,size,tuple_insert_before,pcVar6);
        tuple_new_blockop(0x16b,type,local_10,pcVar5,size,tuple_insert_before,call);
        node_free((c2_node *)size);
      }
      else {
        tuple_new((-(uint)(type != pcVar1->type) & 4) + 0x15b,type,pcVar5,pcVar6->src,
                  tuple_insert_before,pcVar6);
        tuple_new(0x15b,type,dst,pcVar5,tuple_insert_before,call);
        local_10 = dst;
      }
      tuple_unlink_free(pcVar6);
      dst = local_10->next;
      local_10 = dst;
    }
  }
  cfg_remove_edge(fn,from->succs);
  to = fn->cfg->first->succs->to;
  pcVar6 = to->head->next;
  if (pcVar6->kind != '\x1a') {
    member = (c2_symbol *)label_symbol_new();
    pcVar6 = label_insert_in_block((c2_fe_symbol *)member,to);
  }
  t2 = tuple_new_branch(0x186,'\0',(c2_node *)pcVar6,(c2_operand *)0x0,(c2_tuple *)0x0,
                        (c2_insert_fn *)0x0,(c2_tuple *)0x0);
  tuple_replace(call,(c2_node *)t2);
  cfg_add_edge(fn,from,(pcVar6->u14).block);
  return 1;
}

