#ifndef __MEDIA_ELEMENT_IMPL_HPP__
#define __MEDIA_ELEMENT_IMPL_HPP__

#include "MediaObjectImpl.hpp"
#include "MediaElement.hpp"
#include <EventHandler.hpp>

namespace kurento
{

class MediaType;
class MediaSourceImpl;
class MediaSinkImpl;
class MediaElementImpl;

void Serialize (std::shared_ptr<MediaElementImpl> &object, JsonSerializer &serializer);

class MediaElementImpl : public MediaObjectImpl, public virtual MediaElement
{

public:

  MediaElementImpl ();

  virtual ~MediaElementImpl () {};

  std::vector<std::shared_ptr<MediaSource>> getMediaSrcs ();
  std::vector<std::shared_ptr<MediaSource>> getMediaSrcs (std::shared_ptr<MediaType> mediaType);
  std::vector<std::shared_ptr<MediaSource>> getMediaSrcs (std::shared_ptr<MediaType> mediaType, const std::string &description);
  std::vector<std::shared_ptr<MediaSink>> getMediaSinks ();
  std::vector<std::shared_ptr<MediaSink>> getMediaSinks (std::shared_ptr<MediaType> mediaType);
  std::vector<std::shared_ptr<MediaSink>> getMediaSinks (std::shared_ptr<MediaType> mediaType, const std::string &description);
  void connect (std::shared_ptr<MediaElement> sink);
  void connect (std::shared_ptr<MediaElement> sink, std::shared_ptr<MediaType> mediaType);
  void connect (std::shared_ptr<MediaElement> sink, std::shared_ptr<MediaType> mediaType, const std::string &mediaDescription);

  virtual bool connect (const std::string &eventType, std::shared_ptr<EventHandler> handler);

  class Factory : public virtual MediaObjectImpl::Factory
  {
  public:
    Factory () {};

    virtual std::string getName () const {
      return "MediaElement";
    };

  };

  virtual void invoke (std::shared_ptr<MediaObjectImpl> obj,
                       const std::string &methodName, const Json::Value &params,
                       Json::Value &response);

  virtual void Serialize (JsonSerializer &serializer);

private:

  class StaticConstructor
  {
  public:
    StaticConstructor();
  };

  static StaticConstructor staticConstructor;

};

} /* kurento */

#endif /*  __MEDIA_ELEMENT_IMPL_HPP__ */