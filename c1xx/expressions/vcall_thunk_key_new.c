c1_vcall_thunk_key * __cdecl vcall_thunk_key_new(c1_symbol *member,int arena)

{
  c1_vcall_thunk_key *pcVar1;
  c1_vcall_thunk_key *pcVar2;
  c1_arena *a;
  
  a = g_arenas + arena;
  pcVar1 = (c1_vcall_thunk_key *)a->cur;
  pcVar2 = (c1_vcall_thunk_key *)g_arenas[arena].end;
  a->cur = (c1_u8 *)(pcVar1 + 1);
  if (pcVar2 < pcVar1 + 1) {
    arena_grow(a);
  }
  pcVar1->member = member;
  pcVar1->vtable_offset = (int)member->detail;
  pcVar1->convention = (byte)member->type->flags & 7;
  return pcVar1;
}

