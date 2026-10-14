c1_keyed_cell * __cdecl class_path_outermost_reindexing_parent(c1_keyed_cell *cell)

{
  byte bVar1;
  c1_keyed_cell *pcVar2;
  
  if ((cell != (c1_keyed_cell *)0x0) && ((cell->sym->kind & 0x1f) != 4)) {
    pcVar2 = class_path_outermost_reindexing_parent(cell->key);
    if (pcVar2 != (c1_keyed_cell *)0x0) {
      return pcVar2;
    }
    if (((cell->sym->key_ref & 0x10000) != 0) ||
       ((cell->sym->type != (c1_type *)0x0 &&
        (bVar1 = class_path_step_same_vbase_indices(cell), bVar1 == 0)))) {
      return cell->key;
    }
  }
  return (c1_keyed_cell *)0x0;
}

