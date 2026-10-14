void __fastcall swap_stack_slots(int32_t a,int32_t b)

{
  int iVar1;
  c2_stack_slot *pcVar2;
  c2_stack_slot *pcVar3;
  uint32_t *copy_word;
  c2_stack_slot *pcVar4;
  c2_stack_slot saved_slot;
  
  pcVar2 = g_stack_slots + a;
  pcVar3 = &saved_slot;
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    pcVar3->members = pcVar2->members;
    pcVar2 = (c2_stack_slot *)&pcVar2->interference;
    pcVar3 = (c2_stack_slot *)&pcVar3->interference;
  }
  pcVar2 = g_stack_slots + b;
  pcVar3 = pcVar2;
  pcVar4 = g_stack_slots + a;
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    pcVar4->members = pcVar3->members;
    pcVar3 = (c2_stack_slot *)&pcVar3->interference;
    pcVar4 = (c2_stack_slot *)&pcVar4->interference;
  }
  copy_word = (uint32_t *)&saved_slot;
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    pcVar2->members = (c2_bitset *)*copy_word;
    copy_word = copy_word + 1;
    pcVar2 = (c2_stack_slot *)&pcVar2->interference;
  }
  return;
}

