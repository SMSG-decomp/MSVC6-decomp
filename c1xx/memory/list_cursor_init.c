void __thiscall list_cursor_init(void *cursor,void *first)

{
  *(void **)((int)cursor + 4) = first;
  *(bool *)cursor = first != (void *)0x0;
  return;
}

