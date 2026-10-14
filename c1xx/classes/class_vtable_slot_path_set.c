void __cdecl class_vtable_slot_path_set(int *path,int offset)

{
  *path = offset;
  *(undefined2 *)(path + 1) = 0;
  return;
}

