void __fastcall push_eh_state(c2_eh_state *rec)

{
  int32_t iVar1;
  int iVar2;
  uint uVar3;
  int32_t iVar4;
  
  iVar1 = g_eh_state_counter;
  iVar2 = g_eh_state_counter + 1;
  rec->state = g_eh_state_counter;
  g_eh_state_counter = iVar2;
  if (g_eh_current_state == (c2_eh_state *)0x0) {
    iVar4 = -1;
  }
  else {
    iVar4 = g_eh_current_state->state;
  }
  uVar3 = iVar1 & 0x8000001f;
  rec->to_state = iVar4;
  if ((int)uVar3 < 0) {
    uVar3 = (uVar3 - 1 | 0xffffffe0) + 1;
  }
  rec->hash_next = g_eh_state_hash[uVar3];
  rec->parent = g_eh_current_state;
  g_eh_state_hash[uVar3] = rec;
  g_eh_current_state = rec;
  return;
}

