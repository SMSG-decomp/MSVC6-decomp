c2_init * __fastcall alloc_init_record(int kind)

{
  c2_init *pcVar1;
  int iVar2;
  c2_init *pcVar3;
  
  pcVar1 = g_init_record_free;
  if (g_init_record_free == (c2_init *)0x0) {
    pcVar1 = arena_alloc(0,0x1c);
    pcVar1->kind = kind;
    return pcVar1;
  }
  pcVar3 = g_init_record_free;
  g_init_record_free = (g_init_record_free->u08).header.list_next;
  for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
    pcVar3->kind = 0;
    pcVar3 = (c2_init *)&pcVar3->next;
  }
  pcVar1->kind = kind;
  return pcVar1;
}

