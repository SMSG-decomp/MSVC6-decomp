int * __cdecl sym_list_find_non_tag(int *link,int name)

{
  while( true ) {
    if (link == (int *)0x0) {
      return (int *)0x0;
    }
    if ((*link == name) && ((*(byte *)(link + -2) & 0x1f) != 4)) break;
    link = (int *)link[1];
  }
  return link + -2;
}

