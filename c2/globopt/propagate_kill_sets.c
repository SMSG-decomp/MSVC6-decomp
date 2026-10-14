void __fastcall propagate_kill_sets(c2_symbol *s)

{
  c2_symbol *pcVar1;
  c2_cse_expr *pcVar2;
  c2_symbol *s_00;
  uint32_t uVar3;
  c2_bitset *pcVar4;
  c2_copy_link *pcVar5;
  c2_alias_conflict *pcVar6;
  
  pcVar5 = (s->u38).copy_links;
  if (pcVar5 != (c2_copy_link *)0x0) {
    pcVar4 = s->dependents;
    do {
      pcVar1 = pcVar5->source;
      uVar3 = bitset_or_changed(pcVar1->dependents,pcVar4);
      if (uVar3 != 0) {
        propagate_kill_sets(pcVar1);
      }
      pcVar5 = pcVar5->next_of_copy;
    } while (pcVar5 != (c2_copy_link *)0x0);
  }
  pcVar1 = s->storage;
  if (((pcVar1->u18).expr != (c2_cse_expr *)0x0) &&
     (s_00 = pcVar1, pcVar1->storage->part_next != (c2_symbol *)0x0)) {
    for (; s_00 != (c2_symbol *)0x0; s_00 = s_00->part_next) {
      if (s_00 != s) {
        if ((s_00->offset < s->size + s->offset) && (s->offset < s_00->size + s_00->offset)) {
          if (s_00->dependents == (c2_bitset *)0x0) {
            pcVar4 = bitset_new(0xd);
            s_00->dependents = pcVar4;
            bitset_set(pcVar4,s_00->id);
          }
          pcVar4 = s->dependents;
          uVar3 = bitset_or_changed(s_00->dependents,pcVar4);
          if (uVar3 != 0) {
            propagate_kill_sets(s_00);
          }
          uVar3 = bitset_or_changed(pcVar4,s_00->dependents);
          if (uVar3 != 0) {
            propagate_kill_sets(s);
          }
        }
      }
    }
  }
  if (pcVar1->fe == (c2_fe_symbol *)0x0) {
    pcVar2 = (pcVar1->u18).expr;
    if (((pcVar2 != (c2_cse_expr *)0x0) && (pcVar2->op == 0x14c)) &&
       (pcVar6 = g_alias_conflicts[(pcVar2->operands->next->u18).lo],
       pcVar6 != (c2_alias_conflict *)0x0)) {
      pcVar4 = s->dependents;
      do {
        uVar3 = pcVar6->cls;
        if (g_alias_class_kill_sets2[uVar3] != (c2_bitset *)0x0) {
          bitset_or(g_alias_class_kill_sets2[uVar3],pcVar4);
        }
        bitset_or(g_alias_class_kill_sets[uVar3],pcVar4);
        pcVar6 = pcVar6->next;
      } while (pcVar6 != (c2_alias_conflict *)0x0);
    }
  }
  else if ((((pcVar1->cls == '\a') || (pcVar1->cls == '\b')) || ((pcVar1->flags5 & 2) != 0)) &&
          (pcVar6 = g_alias_conflicts[(pcVar1->fe->u3e).alias_class],
          pcVar6 != (c2_alias_conflict *)0x0)) {
    pcVar4 = s->dependents;
    do {
      bitset_or(g_alias_class_kill_sets[pcVar6->cls],pcVar4);
      pcVar6 = pcVar6->next;
    } while (pcVar6 != (c2_alias_conflict *)0x0);
    return;
  }
  return;
}

