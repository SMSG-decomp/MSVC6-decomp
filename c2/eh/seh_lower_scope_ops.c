void __fastcall seh_lower_scope_ops(c2_function *fn)

{
  ushort uVar1;
  c2_tuple *pcVar2;
  c2_tuple *pcVar3;
  c2_symbol *sym;
  c2_tuple *anchor;
  c2_fe_symbol *pcVar4;
  c2_operand *pcVar5;
  c2_operand *pcVar6;
  c2_seh_try_scope *pcVar7;
  c2_tuple *t;
  int level;
  
  pcVar2 = fn->cfg->last->end;
  anchor = fn->cfg->first->head->next;
  pcVar7 = g_seh_try_records;
  while (g_seh_try_records = pcVar7, anchor != pcVar2) {
    pcVar3 = anchor->next;
    if ((anchor->flags & 1) != 0) {
      uVar1 = anchor->line;
      if (uVar1 != 0) {
        g_current_line_abs = fn->line_base + (uint)uVar1;
        g_cur_line = uVar1;
      }
      switch(anchor->op) {
      case 400:
        if ((anchor->u20).intrinsic.id == 0xd9) {
          pcVar7 = seh_current_scope_record();
          while ((pcVar7 != (c2_seh_try_scope *)0x0 && ((pcVar7->flags & 0xc) == 0))) {
            level = pcVar7->parent_level;
            if (pcVar7->parent_level < pcVar7->enclosing_level) {
              level = pcVar7->enclosing_level;
            }
            pcVar7 = seh_find_try_record(g_seh_try_records,level);
          }
          pcVar5 = operand_for_fe_symbol(pcVar7->exception_info_local);
          if (pcVar5->type != anchor->type) {
            operand_set_type(pcVar5,anchor->type);
          }
          t = tuple_new(0x15b,anchor->type,anchor->dst,pcVar5,tuple_insert_before,anchor);
          if (((1 << (t->dst->kind & 0x1f) & 6U) != 0) &&
             (sym = t->dst->sym, sym->def != (c2_tuple *)0x0)) {
            if (sym->storage->part_next == (c2_symbol *)0x0) {
              sym->def = t;
            }
            else {
              symbol_mark_overlapping_parts(sym,t);
            }
          }
          tuple_unlink_free(anchor);
        }
        break;
      case 0x192:
        pcVar7 = (anchor->u20).seh_scope;
        seh_scope_stack_push(pcVar7);
        if (((byte)pcVar7->flags & 1) == 1) {
          pcVar4 = fe_symbol_new_local_cur(3,4,1,1,'\x04',0);
          pcVar7->exception_info_local = pcVar4;
        }
        break;
      case 0x194:
      case 0x196:
        ((anchor->u20).seh_scope)->flags = ((anchor->u20).seh_scope)->flags | 8;
        break;
      case 0x195:
      case 0x197:
        pcVar7 = seh_current_scope_record();
        pcVar7->flags = pcVar7->flags & 0xfffffff7;
        seh_scope_stack_pop();
        break;
      case 0x198:
        pcVar7 = (anchor->u20).seh_scope;
        pcVar7->flags = pcVar7->flags | 4;
        if ((pcVar7->info_use & 3) != 0) {
          pcVar5 = operand_for_fe_symbol(pcVar7->exception_info_local);
          operand_set_type(pcVar5,anchor->type);
          pcVar6 = operand_claim(pcVar5);
          pcVar5 = anchor->dst;
          anchor->dst = pcVar6;
          pcVar6->next = pcVar5;
        }
        break;
      case 0x19a:
        pcVar7 = seh_current_scope_record();
        pcVar7->flags = pcVar7->flags & 0xfffffffb;
      }
    }
    anchor = pcVar3;
    pcVar7 = g_seh_try_records;
  }
  fn->seh_try_scopes = pcVar7;
  for (; pcVar7 != (c2_seh_try_scope *)0x0; pcVar7 = pcVar7->next) {
    pcVar7->written_symbols = (c2_seh_symbol_cell **)0x0;
  }
  arena_reset(4);
  return;
}

