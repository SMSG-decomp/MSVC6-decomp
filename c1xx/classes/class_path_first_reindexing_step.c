c1_keyed_cell * __cdecl class_path_first_reindexing_step(c1_keyed_cell *cell)

{
  c1_symbol *pcVar1;
  byte bVar2;
  
  while( true ) {
    if ((cell == (c1_keyed_cell *)0x0) || (pcVar1 = cell->sym, (pcVar1->kind & 0x1f) != 0xf)) {
      return (c1_keyed_cell *)0x0;
    }
    if (((pcVar1->key_ref & 0x10000) != 0) ||
       ((pcVar1->type != (c1_type *)0x0 &&
        (bVar2 = class_path_step_same_vbase_indices(cell), bVar2 == 0)))) break;
    cell = cell->key;
  }
  return cell;
}

