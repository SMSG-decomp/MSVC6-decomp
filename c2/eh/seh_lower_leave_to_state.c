c2_tuple * __fastcall
seh_lower_leave_to_state(c2_function *fn,c2_tuple *pos,int target_level,c2_tuple *target_label)

{
  int iVar1;
  c2_seh_try_scope *scope;
  c2_seh_try_scope *crossed;
  c2_tuple *pcVar2;
  
  scope = seh_current_scope_record();
  if ((scope == (c2_seh_try_scope *)0x0) || (crossed = scope, scope->level == target_level)) {
    return (c2_tuple *)0x0;
  }
  do {
    if (crossed->level <= target_level) break;
    if (((crossed->flags & 8) == 0) && (crossed->kind == 2)) {
      crossed->flags = crossed->flags | 2;
    }
    crossed = seh_find_try_record(g_seh_try_records,crossed->enclosing_level);
  } while (crossed != (c2_seh_try_scope *)0x0);
  if (scope->marker_op == 0x194) {
    pcVar2 = seh_insert_state_store_17b(0,pos);
    fn->flags = fn->flags | 0x2000;
    if (scope->enclosing_level == -1) {
      return pcVar2;
    }
    scope = seh_find_try_record(g_seh_try_records,scope->enclosing_level);
  }
  iVar1 = scope->level;
  while (iVar1 != target_level) {
    if (scope->kind == 2) {
      pcVar2 = seh_insert_state_store_17a(target_level,pos,target_label);
      return pcVar2;
    }
    if (scope->enclosing_level == -1) break;
    scope = seh_find_try_record(g_seh_try_records,scope->enclosing_level);
    iVar1 = scope->level;
  }
  pcVar2 = seh_insert_state_store_17d(target_level,pos);
  return pcVar2;
}

