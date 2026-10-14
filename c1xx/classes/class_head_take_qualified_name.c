byte __thiscall class_head_take_qualified_name(void *head,c1_u8 *token)

{
  undefined4 uVar1;
  
  *(c1_u8 **)((int)head + 8) = token;
  uVar1 = **(undefined4 **)(token + 8);
  *(undefined4 *)head = 0;
  *(undefined4 *)((int)head + 4) = uVar1;
  return 1;
}

