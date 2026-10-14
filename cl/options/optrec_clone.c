optrec * __cdecl optrec_clone(optrec *r)

{
  optrec *copy;
  
  copy = optrec_new(r->name,r->value,r->passes,r->flags);
  copy->src = r->src;
  return copy;
}

