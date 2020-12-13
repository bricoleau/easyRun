#ifndef callbacks_h
#define callbacks_h

//Common template
template<typename T>
class callbackTemplate
{
  public :
    typedef T callback_t;

  protected :
    callback_t _callback;

  public :
    inline callbackTemplate(callback_t callback) :  _callback(callback) {}

    inline void set(callback_t callback)           {_callback = callback;}
    inline void unset()                            {set(NULL);}
    inline callback_t get()                  const {return _callback;}
    inline bool isSetTo(callback_t callback) const {return get() == callback;}
    inline bool isNotSet()                   const {return isSetTo(NULL);}
    inline bool isSet()                      const {return !isNotSet();}

    inline operator bool() {return isSet();}
    callbackTemplate& operator =(callback_t callback) {set(callback); return *this;}
};

//callback for calling "void function()"
class callbackVoid : public callbackTemplate<void (*)()>
{
  public :
    inline callbackVoid(callback_t callback = NULL) : callbackTemplate(callback) {}
    inline void execute() const {if (isSet()) _callback();}
};

//callback for calling "void function(uint32_t time)"
class callbackTime : public callbackTemplate<void (*)(uint32_t)>
{
  public :
    inline callbackTime(callback_t callback = NULL) : callbackTemplate(callback) {}
    inline void execute(uint32_t time) const {if (isSet()) _callback(time);}
};

#endif
