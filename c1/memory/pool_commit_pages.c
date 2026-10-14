c1_u8 * __thiscall pool_commit_pages(fe_arena *a,int pages,int *bytes_left)

{
  c1_u8 *pcVar1;
  uchar *puVar2;
  uchar *puVar3;
  int iVar4;
  
  pcVar1 = a->cur;
  puVar3 = a->base + (((uint)(pcVar1 + ((pages + 1) * g_system_info.dwPageSize - (int)a->base) + -1)
                      & ~(g_system_info.dwPageSize - 1)) - (int)pcVar1);
  *bytes_left = (int)puVar3;
  puVar2 = a->cur;
  a->cur = puVar3 + (int)puVar2;
  if ((a->end < puVar3 + (int)puVar2) && (iVar4 = arena_grow(a), (char)iVar4 == '\0')) {
    return (c1_u8 *)0x0;
  }
  return pcVar1;
}

