void __cdecl class_vtable_slot_path_set_vbase(int *path,c1_symbol *vbase)

{
  if ((short)path[1] == 0) {
    *(c1_u16 *)(path + 1) = ((vbase->detail).cls)->scope_index;
  }
  return;
}

