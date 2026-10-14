void __cdecl class_vtable_slot_path_add_offset(int *path,int offset)

{
  if ((short)path[1] == 0) {
    *path = *path + offset;
  }
  return;
}

