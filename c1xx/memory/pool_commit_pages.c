c1_u8 * __thiscall pool_commit_pages(c1_arena *a,int npages,c1_u32 *size_out)

{
  c1_u8 *pcVar1;
  c1_u8 *pcVar2;
  c1_u8 *pcVar3;
  int iVar4;
  
  pcVar1 = a->cur;
  pcVar3 = a->base + (((uint)(pcVar1 + ((npages + 1) * g_system_info.dwPageSize - (int)a->base) + -1
                             ) & ~(g_system_info.dwPageSize - 1)) - (int)pcVar1);
  *size_out = (c1_u32)pcVar3;
  pcVar2 = a->cur;
  a->cur = pcVar3 + (int)pcVar2;
  if ((a->end < pcVar3 + (int)pcVar2) && (iVar4 = arena_grow(a), (char)iVar4 == '\0')) {
    return (c1_u8 *)0x0;
  }
  return pcVar1;
}

