c2_tuple * __fastcall eh_funclet_entry_tuple(c2_tuple *t)

{
  return ((t->u20).eh_construct)->object->funclet->cfg->first->head;
}

