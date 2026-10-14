c1_symbol * __cdecl member_path_class(int *path)

{
  uint *cell;
  
  cell = (uint *)*path;
  while( true ) {
    if (cell == (uint *)0x0) {
      return (c1_symbol *)0x0;
    }
    if ((*(byte *)cell[2] & 0x1f) == 4) break;
    cell = (uint *)*cell;
  }
  return (c1_symbol *)cell[2];
}

