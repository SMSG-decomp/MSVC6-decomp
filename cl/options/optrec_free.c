void __cdecl optrec_free(optrec *r)

{
  xfree(r->value);
  xfree(r->name);
  xfree(r->passes);
  r->next = g_optrec_free_list;
  g_optrec_free_list = r;
  return;
}

