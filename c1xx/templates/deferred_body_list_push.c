void __fastcall deferred_body_list_push(c1_deferred_body_list **head)

{
  c1_deferred_body_list *pcVar1;
  
  pcVar1 = (c1_deferred_body_list *)g_arenas[3].cur;
  g_arenas[3].cur = g_arenas[3].cur + 0xc;
  if (g_arenas[3].end < g_arenas[3].cur) {
    arena_grow(g_arenas + 3);
  }
  if (pcVar1 == (c1_deferred_body_list *)0x0) {
    pcVar1 = (c1_deferred_body_list *)0x0;
  }
  else {
    *(c1_u8 *)((int)pcVar1 + 0) = '\0';
    *(c1_u8 *)((int)pcVar1 + 1) = '\0';
    *(c1_u8 *)((int)pcVar1 + 2) = '\0';
    *(c1_u8 *)((int)pcVar1 + 3) = '\0';
    *(c1_u8 *)((int)pcVar1 + 4) = '\0';
    *(c1_u8 *)((int)pcVar1 + 5) = '\0';
    *(c1_u8 *)((int)pcVar1 + 6) = '\0';
    *(c1_u8 *)((int)pcVar1 + 7) = '\0';
    *(c1_u8 *)((int)pcVar1 + 8) = '\0';
    *(c1_u8 *)((int)pcVar1 + 9) = '\0';
    *(c1_u8 *)((int)pcVar1 + 10) = '\0';
    *(c1_u8 *)((int)pcVar1 + 0xb) = '\0';
  }
  if (*head != (c1_deferred_body_list *)0x0) {
    pcVar1->outer = *head;
  }
  *head = pcVar1;
  return;
}

