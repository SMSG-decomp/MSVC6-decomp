char __cdecl option_pass_letter_in(optrec *opt,char *letters)

{
  char *hit;
  
  hit = strpbrk(opt->passes,letters);
  if (hit == (char *)0x0) {
    return '\0';
  }
  return *hit;
}

