void __thiscall using_list_deactivate(void *scope,int ns)

{
  using_cell_release(*(void **)((int)scope + 0x1c),ns);
  return;
}

