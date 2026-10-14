c2_link * __fastcall list_nth(c2_link *list,int n)

{
  for (; n != 0; n = n + -1) {
    list = list->next;
  }
  return list;
}

