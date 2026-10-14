int * __cdecl init_next_member_shares_unit(int offset,int *cell,void *unused)

{
  if (cell == (int *)0x0) {
    return (int *)0x0;
  }
  if ((void *)*cell == g_name_alignment_member) {
    return (int *)0x0;
  }
  return (int *)((uint)cell & (offset != cell[7]) - 1);
}

