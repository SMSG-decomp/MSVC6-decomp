int __cdecl base_path_has_seen_virtual_base(int *path,c1_symtab *seen)

{
  uint *path_cell;
  
  path_cell = (uint *)*path;
  while( true ) {
    if (path_cell == (uint *)0x0) {
      return (uint)path & 0xffffff00;
    }
    path = (int *)path_cell[2];
    if ((((*(byte *)path & 0x1f) == 0xf) && ((*(byte *)((int)path + 0x1a) & 1) != 0)) &&
       (path = symtab_lookup(seen,g_scope_vector->entries[*(short *)((int)path + 0x18)]),
       (byte *)path == (byte *)0x1)) break;
    path_cell = (uint *)*path_cell;
  }
  return 1;
}

