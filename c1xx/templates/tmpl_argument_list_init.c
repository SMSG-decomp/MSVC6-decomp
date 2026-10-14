void * __thiscall tmpl_argument_list_init(void *iter,void *list)

{
  *(void **)iter = list;
  *(void **)((int)iter + 4) = list;
  *(byte *)((int)iter + 8) =
       (*(byte *)((int)iter + 8) ^ *(byte *)((int)list + 0xc) >> 3 & 1) & 1 ^
       *(byte *)((int)iter + 8);
  return iter;
}

